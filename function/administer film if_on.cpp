#include "Header.h"

void film_if_on(wchar_t *name,wchar_t *newinfo)	//���ĵ�Ӱ�Ƿ��ϼܵĺ���
{
	int bkwd=0;
	int m=0;
	int hang=0;
	int i=0;
	char p[]="film list.txt";	
	wchar_t *w=read_file(p);
	for(i=0;i<=wcslen(w);i++)	//����film list.txt�ж�Ӧ��y/n��ǣ�ͨ����ȡ�ı����ݴ���w���飬��ֱ�Ӷ�w��Ӧλ�ý��и��ģ�����w������д�ı�����ʵ��
	{
		int nn=0;
		if(w[i]=='\n'){bkwd++;}
		if((i==0)||((i>0)&&(w[i-1]=='\n')))
		{
			while(w[i]!='\n')
			{
				if(w[i]!=*(name+nn)){break;}
				i++;
				nn++;
			}
		if(nn==wcslen(name)){break;}
		}
	}
	while(hang<=bkwd)
	{
		if(w[m]=='\n'){hang++;}
		m++;
	}
	wchar_t c=*newinfo;
	w[m-4]=c;
	FILE  *fpp;
	if((fpp=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//�򲻿��ļ��ı���
	fwprintf(fpp,w);
	fclose(fpp);
}