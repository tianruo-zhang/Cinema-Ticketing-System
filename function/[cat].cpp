#include "Header.h"

char *cat(wchar_t file[],char package[100])	//�ַ���ƴ�Ӻ��������ڵõ��ļ���
{
	int nLen;	//����wchar_t��char��ת��
	nLen=WideCharToMultiByte(CP_ACP, 0, file, -1, NULL, 0, NULL, NULL);	
	char *pans=(char*)malloc(nLen*(sizeof(char)));
	WideCharToMultiByte(CP_ACP, 0, file,-1,pans,nLen, NULL, NULL);
	strcat(package,"/");	//�������ƴ�ӣ��Ӷ�������ȷ�����ļ�����
	strcat(package,pans);
	strcat(package,".txt");
	return package;		//�����ļ�����
}