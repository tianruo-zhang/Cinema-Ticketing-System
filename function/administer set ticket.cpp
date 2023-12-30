#include "Header.h"

void set_ticket(wchar_t *point)	//administer更改票量的函数，point传入的是存储电影名的字符串
{
	char bb[100]="film";
	char *p=cat(point,bb);
	wchar_t *w=read_file(p);
	int num=wcslen(w);
	printf("\n\n\n------------------------------------------------\nThe followings are the cinema names !\n\n");
	printf("1   STARY SKY CINEMA\n\n");
	printf("2   MIDNIGHT CINEMA\n\n");
	printf("3   PARADISE CINEMA\n\n");
	printf("\n--------------------------------------------------\n");
	wchar_t *cinema=(wchar_t*)malloc(sizeof(wchar_t));
	InputBox(cinema,5,L"please enter the corresponding numeber of the cinema name you would like to set tickets of",NULL,NULL,NULL,100,150);	//读取要修改的电影院编号
	int nn;
	nn=_wtoi(cinema);
	while((nn!=1)&&(nn!=2)&&(nn!=3))		//如果输入的不是对应数字或者输入的数字超过电影院数字范围，则报错要求重新输入
	{
		memset(cinema,0,5*sizeof(wchar_t));
		InputBox(cinema,5,L"please enter the corresponding numeber of the cinema name and make sure it is within range !",NULL,NULL,NULL,100,150);
		nn=_wtoi(cinema);
	}
	printf("\n\n\n------------------------------------------------\nThe followings are the available sessions !\n\n");
	printf("1   MORNING\n\n");
	printf("2   AFTERNOON\n\n");
	printf("3   EVENING\n\n");
	printf("4   NIGHT\n\n");
	printf("\n--------------------------------------------------\n");
	wchar_t *session=(wchar_t*)malloc(sizeof(wchar_t));
	InputBox(session,5,L"please enter the corresponding numeber of the cinema session you would like to set tickets of",NULL,NULL,NULL,100,150);	//读取要修改的电影院编号
	int mm;
	mm=_wtoi(session);
	while((mm!=1)&&(mm!=2)&&(mm!=3)&&(mm!=4))		//如果输入的不是对应数字或者输入的数字超过电影院数字范围，则报错要求重新输入
	{
		memset(session,0,5*sizeof(wchar_t));
		InputBox(session,5,L"please enter the corresponding numeber of the session name and make sure it is correct !",NULL,NULL,NULL,100,150);
		mm=_wtoi(session);
	}

	int hang=9+(nn-1)*4+mm;
	int bkwd=0;
	wchar_t *ticket=(wchar_t*)malloc(sizeof(wchar_t));
	InputBox(ticket,5,L"please set the number of tickets [ given the current situation of COVID-19 and the layout of the screening room , 10 / 15 / 20 / 25 is accepted ]",NULL,NULL,NULL,100,150);	//读取票量
	int t;
	t=_wtoi(ticket);
	while((t!=10)&&(t!=15)&&(t!=20)&&(t!=25))	//确保设定的票量是符合防疫要求并且能和与影院座位布局相适合
	{
		memset(ticket,0,5*sizeof(wchar_t));
		InputBox(ticket,5,L"please set the number of tickets [ given the current situation of COVID-19 and the layout of the screening room , 10 / 15 / 20 / 25 is accepted ]",NULL,NULL,NULL,100,150);
		t=_wtoi(ticket);
	}

	FILE  *fp2;	//对该电影的文本内容进行修改
	if((fp2=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//打不开文件的报错
	int i=0;
	for(i=0;i<=num;i++)
	{
		wchar_t c;
		c=w[i];
		fwprintf(fp2,&c);
		if(w[i]=='\n'){bkwd++;}
		if(bkwd==hang){break;}
	}
	if(t==10){wchar_t pp[]=L"10/ABCDEFGHIJ\n";fwprintf(fp2,pp);}	//总票数标记在前，之后是座位编号，总票数不随user购票而发生更改，但是座位情况会随着user购票发生变化，并可以实时统计余票量
	if(t==15){wchar_t pp[]=L"15/ABCDEFGHIJKLMNO\n";fwprintf(fp2,pp);}
	if(t==20){wchar_t pp[]=L"20/ABCDEFGHIJKLMNOPQRST\n";fwprintf(fp2,pp);}
	if(t==25){wchar_t pp[]=L"25/ABCDEFGHIJKLMNOPQRSTUVWXY\n";fwprintf(fp2,pp);}
	i++;
	while(bkwd==hang)
	{
		if(w[i]=='\n'){bkwd++;}
		i++;
	}
	fwprintf(fp2,&w[i]);
	fclose(fp2);
}