infinite_push_rtmp
Build Status

https://github.com/sqbing/infinite_push_rtmp

����librtmpʵ�ֵ������ͳ���ѭ����ȡ�����flv�ļ�����������Զ�˵�RTMP��������

RTMP push program based on librtmp. Reads in one flv file, and pushes to remote RTMP server infinitely by adapting timestamp.

����/Compile
g++ -i main.cc -l rtmp -o infinite_push

����/Run
./infinite_push -i ~/whatever.flv -o rtmp://xxx.xxx.xxx.xxx/live/test

����/Test
�Ѳ��ԣ���������:

crtmpserver-1.1_beta
nginx-rtmp-module-1.1.4