#ifndef BYTESTREAM_H_ 
#define BYTESTREAM_H_

#include <stdint.h>
#include <string.h>
#include<stdio.h>


/*
nkwavelet �ظ� akagi201:����������Լ�д�ģ����Ƿ������ˣ���˼��������Ӧ��ָ����ָ����ڴ�ռ�ȡһ���ֽڳ�����Ȼ��ָ����ǰ�ƶ�һ���ֽڡ�
bytestream_get_be24()����ȡ3���ֽ�ƴ��һ����������Ȼ��ָ���ƶ�3���ֽڡ���������û��Դ�룬�Լ��ڻ�����һ�ºܿ�ͳ����ˣ�������10�еĴ��롣


[2015-02-11 09:36]
akagi201 �ظ� nkwavelet:��, �������Ļ�, ��ò���һ�°�, �Ҳ����be24�Ǵ�˻���С��,  �����Լ�ʵ����
*/
int bytestream_get_byte(const unsigned char ** buf);
/*�����ˣ����Ҳ��ˣ��ҿ��Ըı�ָ�����*/
int bytestream_get_be24(const unsigned char ** buf);


#endif //BYTESTREAM_H_
