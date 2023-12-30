#include "Header.h"

char *cat(wchar_t file[],char package[100])	//字符串拼接函数，用于得到文件名
{
	int nLen;	//进行wchar_t和char的转换
	nLen=WideCharToMultiByte(CP_ACP, 0, file, -1, NULL, 0, NULL, NULL);	
	char *pans=(char*)malloc(nLen*(sizeof(char)));
	WideCharToMultiByte(CP_ACP, 0, file,-1,pans,nLen, NULL, NULL);
	strcat(package,"/");	//进行相关拼接，从而可以正确生成文件名称
	strcat(package,pans);
	strcat(package,".txt");
	return package;		//返回文件名称
}