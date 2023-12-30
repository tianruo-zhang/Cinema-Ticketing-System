#include "Header.h"

void film_if_on(wchar_t *name,wchar_t *newinfo)	//更改电影是否上架的函数
{
	int bkwd=0;
	int m=0;
	int hang=0;
	int i=0;
	char p[]="film list.txt";	
	wchar_t *w=read_file(p);
	for(i=0;i<=wcslen(w);i++)	//更改film list.txt中对应的y/n标记，通过读取文本内容存入w数组，在直接对w对应位置进行更改，在用w数组重写文本进行实现
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
	if((fpp=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//打不开文件的报错
	fwprintf(fpp,w);
	fclose(fpp);
}