#include "Header.h"

void add_history(wchar_t*pointer)	//���ڽ�user�Ĳ�����¼д��history.txt
{
	int num=0;
	char p[]="history.txt";	
	FILE  *fp;
	if((fp=fopen(p,"a"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//�ļ��򲻿��ı���
	fwprintf(fp,pointer);
	fclose(fp);
}