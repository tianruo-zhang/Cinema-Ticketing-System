#include "Header.h"

int delete_film(wchar_t *name)	//删除某部电影相关信息的函数
{	
	char b[100]="film";		//删除该电影对应的文本文件
	char *pp=cat(name,b);
	int ch1=remove(pp);
	char p[]="film list.txt";	//在film list.txt中删除该电影对应的信息，通过查找到该电影信息所在行数，把该行前和该行后的重新写入文本，实现该行的删除
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
	if((fpp=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//打不开文件的报错
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