#include "Header.h"

int delete_film(wchar_t *name)	//ɾ��ĳ����Ӱ�����Ϣ�ĺ���
{	
	char b[100]="film";		//ɾ���õ�Ӱ��Ӧ���ı��ļ�
	char *pp=cat(name,b);
	int ch1=remove(pp);
	char p[]="film list.txt";	//��film list.txt��ɾ���õ�Ӱ��Ӧ����Ϣ��ͨ�����ҵ��õ�Ӱ��Ϣ�����������Ѹ���ǰ�͸��к������д���ı���ʵ�ָ��е�ɾ��
	wchar_t *w=read_file(p);
	int bkwd=0;
	int i=0;
	for(i=0;i<=wcslen(w);i++)
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
	FILE  *fpp;
	if((fpp=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//�򲻿��ļ��ı���
	wchar_t *temp=(wchar_t*)malloc(sizeof(wchar_t));
	int hang=0;
	int m=0;
	for(hang=0;hang<bkwd;)
	{
		temp[m]=w[m];
		temp=(wchar_t*)realloc(temp,(m+2)*sizeof(wchar_t));
		if(w[m]=='\n'){hang++;}
		m++;
	}
	temp[m]=L'\0';
	fwprintf(fpp,temp);
	while(hang==bkwd)
	{
		if(w[m]=='\n'){bkwd++;}
		m++;
	}
	fwprintf(fpp,&w[m]);
	fclose(fpp);
	return ch1;
}