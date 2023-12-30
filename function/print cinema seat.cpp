#include "Header.h"

void print_seat(wchar_t *point,int numm)	//打印电影座位的函数
{
	int num=0;
	char b[100]="film";
	char *p=cat(point,b);
	wchar_t *w=read_file(p);
	num=wcslen(w);
	int hang=(numm-1)*4+10;	//找到电影信息中对应电影院的行数，numm是影院序号，hang是目标行数
	int bkwd=0;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(w[i]=='\n'){bkwd++;}
		if(bkwd==hang){break;}
	}
	i++;
	while(hang<numm*4+10)	//用循环体打印各个电影院的各个场次的座位信息
	{
		while(w[i]!='/')
		{
			i++;
		}
		i++;
		int sum=0;	//用于打印时的换行操作
		int seat=0;		//各影院余票数计数
		switch(hang-(numm-1)*4-10)
		{
		case 0:{printf("\nMORNING SESSION:\n\n");break;}
		case 1:{printf("\nAFTERNOON SESSION:\n\n");break;}
		case 2:{printf("\nEVENING SESSION:\n\n");break;}
		case 3:{printf("\nNIGHT:\n\n");break;}
		}
		while(w[i]!='\n')		//按照电影院实际座位布局打印出剩余座位情况
		{
			wchar_t c=w[i];
			if((c>=L'A')&&(c<='Z')){seat++;}
			wprintf(L"%c",c);
			printf("     ");
			sum++;
			i++;
			if(sum%5==0){printf("\n\n\n");}
		}
		printf("%d SEAT(S) REMAINED !\n\n",seat);	//最后输出余票量，便于user查看
		i++;
		hang++;
	}
}