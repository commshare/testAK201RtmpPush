/*
 * @file CRtmpStream.cpp
 * @author Akagi201
 * @date 2015/02/10
 */

#include <unistd.h>
#include"lwlog/lwlog.h"

#include "CRtmpStream.h"
#include "bytestream.h"
#include<iostream>
using namespace std;

char *put_byte(char *output, uint8_t nVal) {
    output[0] = nVal;

    return output + 1;
}

/*
把一个占用了两个字节的数据，低八位存在缓冲的高地址，高八位存在低地址。
如果缓冲代表的是小端存储，那么输入的数据是大端模式的。
那这个实际上市大端转小端�
*/
char *put_be16(char *output, uint16_t nVal) {
    output[1] = nVal & 0xff;
    output[0] = nVal >> 8;

    return output + 2;
}

char *put_be24(char *output, uint32_t nVal) {
    output[2] = nVal & 0xff;
    output[1] = nVal >> 8;
    output[0] = nVal >> 16;

    return output + 3;
}

char *put_be32(char *output, uint32_t nVal) {
    output[3] = nVal & 0xff;
    output[2] = nVal >> 8;
    output[1] = nVal >> 16;
    output[0] = nVal >> 24;

    return output + 4;
}

char *put_be64(char *output, uint64_t nVal) {
    output = put_be32(output, nVal >> 32);
    output = put_be32(output, nVal);

    return output;
}

char *put_amf_string(char *c, const char *str) {
    uint16_t len = strlen(str);
    c = put_be16(c, len);
    memcpy(c, str, len);

    return c + len;
}

CRtmpStream::CRtmpStream(void) : m_pRtmp(NULL) {
    m_pRtmp = RTMP_Alloc();
    RTMP_Init(m_pRtmp);

    m_pFid = NULL;
    m_nDstSocket = -1;

    return;
}

CRtmpStream::~CRtmpStream(void) {
    return;
}

bool CRtmpStream::Connect(const char *url) {
    if (RTMP_SetupURL(m_pRtmp, (char *) url) < 0) {
        return FALSE;
    }

    RTMP_EnableWrite(m_pRtmp);

    if (RTMP_Connect(m_pRtmp, NULL) < 0) {
        return FALSE;
    }

    m_nDstSocket = m_pRtmp->m_sb.sb_socket;

    if (RTMP_ConnectStream(m_pRtmp, 0) < 0) {
        return FALSE;
    }

    return TRUE;
}

void CRtmpStream::Close(void) {
    if (m_pRtmp) {
        RTMP_Close(m_pRtmp);
        RTMP_Free(m_pRtmp);
        m_pRtmp = NULL;
    }

    if (m_pFid) {
        fclose(m_pFid);
        m_pFid = NULL;
    }

    return;
}

/*
 * @brief 获取flv文件头数据, 包括metadata数据和其后的previous tag size, 返回文件头字节大学
 */
int CRtmpStream::GetFlvHeader(unsigned char *buf) {
    // 读取flv文件头9 + 4
    fread(buf, 13, 1, m_pFid);
     int i=0;
     /*http://smartgeek.iteye.com/blog/1543825
     hh 将会将 int 转化成 char；unsigned int 转化成 unsigned char */
     for(i=0;i<13;i++){
        printf( "the hex value of a is 0x%02hhx\n", buf[i] );
     }
     /*11个字节的tag header信息，
其中 Tag Header由11个字节组成：

第1个字节：表示类型，0x08表示音频，0x09表示视频，0x12表示Script Data；
第2-4字节：表示当前Tag Data的长度；
第5-7字节：表示Tag的时间戳，以毫秒为单位；
第8字节：时间戳的扩展字节，用于扩充上面的时间戳；
第9-11字节：表示Stream ID，总为0。

     */
    // 读取tag header
    fread(buf + 13, 11, 1, m_pFid);

    /*ox12,代表第一个tag是MetadataTag*/
    unsigned char type = buf[13];
    printf( "the hex value of type is 0x%02hhx\n", type );

    /*这应该就可以说明FLV文件存储数据是按照大端来存储的，因为内存低地址，存放的是高位数据
            http://www.oschina.net/translate/understanding-big-and-little-endian-byte-order
            size是占了三个字节的
    */
    unsigned int size = (unsigned char) buf[14] * 256 * 256 + (unsigned char) buf[15] * 256 + (unsigned char) buf[16];
    printf("metadata size[%d]\n",size);
    // 读取metadata数据, 包括其后的previous tag size
    if (0x12 == type) { /*0x12表示Script Data*/
        fread(buf + 24, size + 4, 1, m_pFid);
        return size + 24 + 4;
    } else {
        printf("The first tag is not metadata tag!\n");
        return -1;
    }
}

/*
 * @brief 读取一帧flv数据到buf中, 包括其后的previous tag size
 */
int CRtmpStream::GetFlvFrame(unsigned char *buf) {
    unsigned int framesize = 0;
    unsigned int bodysize = 0;
    static int tagIndex = 0;

    // 读取tag header
    fread(buf, 11, 1, m_pFid);
    framesize += 11;

    // 获取tag的类型
    unsigned char type = buf[0];
    if ((0x08 == type) || (0x09 == type)) {
        ++tagIndex;
    } else {
        printf("Error while reading flv frame!\n");
        return -1;
    }

    // 获取bodysize
    bodysize = (unsigned char) buf[1] * 256 * 256 + (unsigned char) buf[2] * 256 + (unsigned char) buf[3];
    fread(buf + 11, bodysize, 1, m_pFid);
    framesize += bodysize;
    printf("\n%s Tag%d Size: %d\n", (type == 0x08) ? "Audio" : ((type == 0x09) ? "Video" : "Metadata"), tagIndex, framesize);

    // 将4个字节的previous size读取到buf中
    fread(buf + framesize, 4, 1, m_pFid);
    framesize += 4;

    return framesize;
}

/*
 * @brief 发送flv文件头
 */
int CRtmpStream::SendFlvHeader(unsigned char *buf, int size) {

    uint32_t timestamp;
    int ret = 0;
    int pktSize, pktType;
    unsigned char *pHeader = buf + 13;

    // 获取metadata tag的头信息(11个字节)、
    /*
type                一个字节  18
data size          三个字节   397
timestamp         四个字节      0
streamid          三个字节     0
    */
    pktType = bytestream_get_byte((const unsigned char **) &pHeader);

    lwlog_info("pktType[%d]", pktType);
    pktSize = bytestream_get_be24((const unsigned char **) &pHeader);
    lwlog_info("pktSize[%d]", pktSize);
    timestamp = bytestream_get_be24((const unsigned char **) &pHeader);
    lwlog_info("#1#timestamp[%d]", timestamp);
    timestamp |= bytestream_get_byte((const unsigned char **) &pHeader) << 24;
    lwlog_info("#2#timestamp[%d]", timestamp);
    bytestream_get_be24((const unsigned char **) &pHeader);
    lwlog_info("okokok");
    // 构造RTMP包
    RTMPPacket packet;
    RTMPPacket_Reset(&packet);
    ret = RTMPPacket_Alloc(&packet, size + 16);
    if (!ret) {
        lwlog_err("RTMPPacket_Alloc fail");
        return -1;
    }

    packet.m_packetType = pktType;
    packet.m_nBodySize = pktSize + 16;
    packet.m_nTimeStamp = timestamp;
    packet.m_nChannel = 4;
    packet.m_headerType = RTMP_PACKET_SIZE_LARGE;
    packet.m_nInfoField2 = m_pRtmp->m_stream_id;

    uint8_t *body = (uint8_t *) packet.m_body;
    put_amf_string((char *) body, "@setDataFrame");
    memcpy(body, buf + 24, pktSize);

    /*dump for debug*/
    RTMPPacket_Dump(&packet);
    cout<<"before send flvheader pkt "<<endl;
    ret = RTMP_SendPacket(m_pRtmp, &packet, 0);

    return ret;
}

/*
 * @brief 发送flv一帧
 */
int CRtmpStream::SendFlvFrame(unsigned char *buf, int size) {
    uint32_t timestamp;
    int ret = 0;
    int pktSize, pktType;
    unsigned char *pHeader = buf;

    // 获取tag header信息(11个字节)
    pktType = bytestream_get_byte((const unsigned char **) &pHeader);
    pktSize = bytestream_get_be24((const unsigned char **) &pHeader);
    timestamp = bytestream_get_be24((const unsigned char **) &pHeader);
    timestamp |= bytestream_get_byte((const unsigned char **) &pHeader) << 24;
    bytestream_get_be24((const unsigned char **) &pHeader);

    // 构造RTMP包
    RTMPPacket packet;
    RTMPPacket_Reset(&packet);
    ret = RTMPPacket_Alloc(&packet, size);
    if (!ret) {
        return -1;
    }

    packet.m_packetType = pktType;
    packet.m_nBodySize = pktSize;
    packet.m_nTimeStamp = timestamp;
    packet.m_nChannel = 0x04;//4;
    packet.m_headerType = RTMP_PACKET_SIZE_LARGE;
    packet.m_nInfoField2 = m_pRtmp->m_stream_id;

    memcpy(packet.m_body, buf + 11, pktSize);

    ret = RTMP_SendPacket(m_pRtmp, &packet, 0);

    return ret;
};

/*
 * @brief 发送flv文件
 */
bool CRtmpStream::SendFlvFile(const char *filename) {
    int size = 0;
    unsigned char buf[SEND_BUF_SIZE] = {0};

    m_pFid = fopen(filename, "rb");
    if (NULL == m_pFid) {
        printf("Can net open the file: %s\n", filename);
        return FALSE;
    }

    size = GetFlvHeader(buf);
    lwlog_info("flvheader size[%d]",size);
    SendFlvHeader(buf, size);
    lwlog_debug("===========after send flv header================");
    #if 0

    // 循环发送每一帧数据
    while (!feof(m_pFid)) {
        memset(buf, 0, SEND_BUF_SIZE);
        size = GetFlvFrame(buf);
        if (size > 0) {
            /*循环发送flv的数据帧*/
            SendFlvFrame(buf, size);
            sleep(40);
        }
    }
    #endif
    return TRUE;
}
