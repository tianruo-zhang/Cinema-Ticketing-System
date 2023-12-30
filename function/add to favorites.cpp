#include "Header.h"

void add_to_favorites(wchar_t *name)	//加入收藏夹的函数
{
	char b[100]="user";	//在对应文件的对应行数写上name中存储的电影名称
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	FILE *fp2;
	if((fp2=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//打不开文件的报错
	int bkwd=0;
	int i=0;
	while(bkwd<3)
	{
		wchar_t c;
		c=w[i];
		fwprintf(fp2,&c);
		i++;	
		if(w[i]=='\n'){bkwd++;}
	}
	fwprintf(fp2,name);
	fwprintf(fp2,L"/");
	fwprintf(fp2,&w[i]);
	fclose(fp2);
}