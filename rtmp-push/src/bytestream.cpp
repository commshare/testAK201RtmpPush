#include"bytestream.h"


/*�����ܷ�ı��ⲿ��pHeader2*/
#define TEST_CHANGE_pHeader2 0
/*buf�Ǵ�ˣ����ص�Ҳ�Ǵ��*/
int bytestream_get_byte(const unsigned char ** buf){
	const	 unsigned char *p=*buf;
  // printf("*buf [%c]\n   [%d] \n [%d]\n",*p,*p,(*p)&&0x000000FF);

	int a= (int)(*p);
	(*buf)=(*buf) + 1;
 	return a;
}

/*�����ˣ����Ҳ��ˣ��ҿ��Ըı�ָ�����*/
int bytestream_get_be24(const unsigned char ** buf){
	 const unsigned char *p=*buf;
     unsigned char a=(*p);
     unsigned char b=(*(p+1));
     unsigned char c=(*(p+2));
    int d=(a<<16) | (b<<8) | (c) ;
    /*d��e�ļ��㷽ʽ��һ����*/
    int e= (a<<16) +(b<<8) + (c) ;
    printf("###e[%d]\n",e);
//	printf("a[%d] \n b[%d] \nc[%d] \n d[%d]\n",a,b,c,d);
//	 printf("#2#move to next \n");
	 #if TEST_CHANGE_pHeader2
	 p=p+3;/*�����ã��ı����p,����ı��ⲿ��pHeader2*/
	 printf("(*p)[%d]\n",*p);
	 #else
//	buf=buf+1;  /*�����ã��ı����buf*/
 p=p+3;
(*buf)=(*buf)+3;

	 printf("(*p)[%d] **buf [%d] d[%d]\n",*p,**buf,d);
	 #endif
     return d;
}
