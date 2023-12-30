#include "Header.h"

void add_history(wchar_t*pointer)	//用于将user的操作记录写入history.txt
{
	int num=0;
	char p[]="history.txt";	
	FILE  *fp;
	if((fp=fopen(p,"a"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//文件打不开的报错
	fwprintf(fp,pointer);
	fclose(fp);
}