#include "Header.h"

wchar_t *add_new_film()	//用于administer增加新电影的函数
{
	//读取各项信息并存入对应数组
	wchar_t *name=(wchar_t*)malloc(30*sizeof(wchar_t));
	InputBox(name,30,L"please enter the name of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *image=(wchar_t*)malloc(200*sizeof(wchar_t));
	InputBox(image,200,L"please enter the image of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *director=(wchar_t*)malloc(100*sizeof(wchar_t));
	InputBox(director,100,L"please enter the director of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *leadrole=(wchar_t*)malloc(200*sizeof(wchar_t));
	InputBox(leadrole,200,L"please enter the leading role of the new film (if needed please use </> to separate):",NULL,NULL,NULL,100,150);
	wchar_t *country=(wchar_t*)malloc(30*sizeof(wchar_t));
	InputBox(country,30,L"please enter the country of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *year=(wchar_t*)malloc(20*sizeof(wchar_t));
	InputBox(year,20,L"please enter the year of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *category=(wchar_t*)malloc(200*sizeof(wchar_t));
	InputBox(category,200,L"please enter the category of the new film (if needed please use </> to separate):",NULL,NULL,NULL,100,150);
	wchar_t *onyear=(wchar_t*)malloc(20*sizeof(wchar_t));
	InputBox(onyear,20,L"please enter the on year of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *introduction=(wchar_t*)malloc(300*sizeof(wchar_t));
	InputBox(introduction,300,L"please enter the introduction of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *ratings=(wchar_t*)malloc(20*sizeof(wchar_t));
	InputBox(ratings,20,L"please enter the ratings of the new film :",NULL,NULL,NULL,100,150);
	wchar_t *if_on=(wchar_t*)malloc(20*sizeof(wchar_t));
	InputBox(if_on,20,L"please enter 'y' or 'n' to determine whether it is on now :",NULL,NULL,NULL,100,150);

	//以一定格式将信息写入新的该电影文本文件中
	char b[100]="film";
	char *p=cat(name,b);
	FILE  *fp;
	if((fp=fopen(p,"a+"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//打不开文件的报错
	fwprintf(fp,name);
	fwprintf(fp,L"\n");
	fwprintf(fp,image);
	fwprintf(fp,L"\n");
	fwprintf(fp,director);
	fwprintf(fp,L"\n");
	fwprintf(fp,leadrole);
	fwprintf(fp,L"\n");
	fwprintf(fp,country);
	fwprintf(fp,L"\n");
	fwprintf(fp,year);
	fwprintf(fp,L"\n");
	fwprintf(fp,category);
	fwprintf(fp,L"\n");
	fwprintf(fp,onyear);
	fwprintf(fp,L"\n");
	fwprintf(fp,introduction);
	fwprintf(fp,L"\n");
	fwprintf(fp,ratings);
	fwprintf(fp,L"\n");		//打印之后的空行

	printf("\n\n\n------------------------------------------------\nThe order of the ticket number waiting to be set!\n\n");
	printf("STARY SKY CINEMA : MORNING AFTERNOON EVENING NIGHT\n\n");
	printf("MIDNIGHT CINEMA : MORNING AFTERNOON EVENING NIGHT\n\n");
	printf("PARADISE CINEMA : MORNING AFTERNOON EVENING NIGHT\n\n");
	printf("\n\n-------------------------------------------------\n\n");
	for(int y=0;y<=11;y++)	//设置座位信息
	{
		wchar_t *ticket=(wchar_t*)malloc(sizeof(wchar_t));
		InputBox(ticket,5,L"please set the number of tickets according to the order given on the console [ given the current situation of COVID-19 and the layout of the screening room , 10 / 15 / 20 / 25 is accepted ]",NULL,NULL,NULL,100,150);	//读取票量
		int t;
		t=_wtoi(ticket);
		while((t!=10)&&(t!=15)&&(t!=20)&&(t!=25))	//确保设定的票量是符合防疫要求并且能和与影院座位布局相适合
		{
			memset(ticket,0,5*sizeof(wchar_t));
			InputBox(ticket,5,L"please set the number of tickets [ given the current situation of COVID-19 and the layout of the screening room , 10 / 15 / 20 / 25 is accepted ]",NULL,NULL,NULL,100,150);
			t=_wtoi(ticket);
		}
		if(t==10){wchar_t pp[]=L"10/ABCDEFGHIJ\n";fwprintf(fp,pp);}	
		if(t==15){wchar_t pp[]=L"15/ABCDEFGHIJKLMNO\n";fwprintf(fp,pp);}
		if(t==20){wchar_t pp[]=L"20/ABCDEFGHIJKLMNOPQRST\n";fwprintf(fp,pp);}
		if(t==25){wchar_t pp[]=L"25/ABCDEFGHIJKLMNOPQRSTUVWXY\n";fwprintf(fp,pp);}
	}
	fclose(fp);

	//在film list.txt中写入该电影信息
	FILE  *fp2;
	char pp[]="film list.txt";
	if((fp2=fopen(pp,"a"))==NULL){printf("\n The file: %s  can not  be  opened \n",pp);exit(1);}
	fwprintf(fp2,name);
	fwprintf(fp2,L"/");
	fwprintf(fp2,ratings);
	fwprintf(fp2,L"/");
	fwprintf(fp2,if_on);
	fwprintf(fp2,L"//\n");
	fclose(fp2);

	//控制台上打印相关录入信息以供administer确认
	printf("\n\n\n------------------------------------------------\nThe following is the info of the new film you have just added !\n\n");
	wprintf(L"NAME : ");
	wprintf(name);
	wprintf(L"\n\n");
	wprintf(L"IMAGE : ");
	wprintf(image);
	wprintf(L"\n\n");
	wprintf(L"DIRECTOR : ");
	wprintf(director);
	wprintf(L"\n\n");
	wprintf(L"LEADING ROLES : ");
	wprintf(leadrole);
	wprintf(L"\n\n");
	wprintf(L"COUNTRY : ");
	wprintf(country);
	wprintf(L"\n\n");
	wprintf(L"YEAR : ");
	wprintf(year);
	wprintf(L"\n\n");
	wprintf(L"CATEGORY : ");
	wprintf(category);
	wprintf(L"\n\n");
	wprintf(L"ON YEAR : ");
	wprintf(onyear);
	wprintf(L"\n\n");
	wprintf(L"BRIEF INTRODUCTION : ");
	wprintf(introduction);
	wprintf(L"\n\n");
	wprintf(L"RATINGS : ");
	wprintf(ratings);
	wprintf(L"\n\n");
	printf("--------------------------------------------------\n");
	return name;
}