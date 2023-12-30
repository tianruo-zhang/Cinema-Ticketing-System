#include "Header.h"

void print_favorites()	//打印用户的收藏夹，起到查看收藏夹的功能
{
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int bkwd=0;
	int i=0;
	while(bkwd<2)	//找到收藏夹所在的对应行数
	{
		i++;	
		if(w[i]=='\n'){bkwd++;}
	}
	i++;
	printf("\n\n\n------------------------------------------------\nThe following is your <FAVORITES> !\n\n");
	if(w[i]!='\n')
	{
		while(w[i]!='\n')
		{
			wchar_t tt;		//进行逐个字符的输出
			tt=w[i];
			if(tt!='/'){wprintf(&tt);}
			if(tt=='/'){wprintf(L"\n\n");}	
			i++;	
		}
	}
	else("no info !\n\n");		//当没有信息输出时
	printf("--------------------------------------------------\n");
}