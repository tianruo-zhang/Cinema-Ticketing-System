#include "Header.h"

void edit_seat(wchar_t *name,wchar_t *cinema,wchar_t *session,wchar_t *seat)	//在user购票后更改电影文本中的座位信息的函数
{
	int num=0;
	char b[100]="film";
	char *p=cat(name,b);
	wchar_t *w=read_file(p);
	num=wcslen(w);	//数组长度
	int numm=_wtoi(cinema);	//字符串转换为整型数
	int nn=_wtoi(session);
	int hang=9+(numm-1)*4+nn;	//找到需要修改的对应行数，这通过对应的电影院名称即可推断
	int bkwd=0;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(w[i]=='\n'){bkwd++;}
		if(bkwd==hang){break;}
	}
	i++;
	while(w[i]!='/')
	{
		i++;
	}
	i++;
	while(1)
	{
		wchar_t cc=w[i];
		if(cc==*seat){w[i]=L' ';break;}	//当这个位置被购票后，标记座位的字符串的对应位置修改为一个空格（在读取文件存入的w数组中直接修改，之后再用w重写文本）
		i++;
	}
	FILE  *fp2;
	if((fp2=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//打不开文件的报错
	fwprintf(fp2,w);
	fclose(fp2);
}