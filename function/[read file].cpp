#include "Header.h"

wchar_t *read_file(char *p)	//��ȡp��Ӧ���ļ��е��ַ�������w���飬����������ַ������и��ĵĲ���
{
	int ch;
	int num=0;
	wchar_t *w=(wchar_t*)malloc(sizeof(wchar_t));
	FILE  *fp;
	if((fp=fopen(p,"r"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//�򲻿��ļ��ı���
	ch=fgetc(fp);	
	while (ch!=EOF)
	{
		w[num]=ch;	
		num++;
		w=(wchar_t*)realloc(w,(num+1)*sizeof(wchar_t));
		ch=fgetc(fp);
	}
	fclose(fp);
	w[num]=L'\0';
	return w;
}