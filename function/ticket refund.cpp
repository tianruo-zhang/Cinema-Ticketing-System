#include "Header.h"

void ticket_refund()	//用户进行退票操作的函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	print_ticket_info(1);
	wchar_t *name=(wchar_t*)malloc(50*sizeof(wchar_t));		//获取所需退票的信息，包括电影名称、电影院名称、放映场次、座位号
	InputBox(name,50,L"please enter the name of the film you would like to get refund of !",NULL,NULL,NULL,100,150);
	wchar_t *cinema=(wchar_t*)malloc(30*sizeof(wchar_t));
	InputBox(cinema,30,L"please enter the correspoding number of cinema (1 FOR STARY SKY CINEMA / 2 FOR MIDNIGHT CINEMA / 3 FOR PARADISE CINEMA )!",NULL,NULL,NULL,100,150);
	int nn=_wtoi(cinema);		//电影院序号转换为整型数
	while((nn!=1)&&(nn!=2)&&(nn!=3))		//输入检查
	{
		memset(cinema,0,30*sizeof(wchar_t));
		InputBox(cinema,30,L"please enter the correspoding number of cinema and make sure it is correct (1 FOR STARY SKY CINEMA / 2 FOR MIDNIGHT CINEMA / 3 FOR PARADISE CINEMA ) !",NULL,NULL,NULL,100,150);
		nn=_wtoi(cinema);
	}
	switch(nn)
	{
	case 1:{cinema=L"STARY SKY CINEMA";break;}
	case 2:{cinema=L"MIDNIGHT CINEMA";break;}
	case 3:{cinema=L"PARADISE CINEMA";break;}
	}
	wchar_t *session=(wchar_t*)malloc(5*sizeof(wchar_t));
	InputBox(session,5,L"please enter the correspoding number of session ( 1 FOR MORNING / 2 FOR AFTERNOON / 3 FOR EVENING /4 FOR NIGHT)!",NULL,NULL,NULL,100,150);
	int mm=_wtoi(session);		//场次序号转换为整型数
	while((mm!=1)&&(mm!=2)&&(mm!=3)&&(mm!=4))		//检查输入
	{
		memset(session,0,5*sizeof(wchar_t));
		InputBox(session,5,L"please enter the correspoding number of session and make sure it is correct ( 1 FOR MORNING / 2 FOR AFTERNOON / 3 FOR EVENING /4 FOR NIGHT)!",NULL,NULL,NULL,100,150);
		mm=_wtoi(session);
	}
	switch(mm)
	{
	case 1:{session=L"MORNING SESSION";break;}
	case 2:{session=L"AFTERNOON SESSION";break;}
	case 3:{session=L"EVENING SESSION";break;}
	case 4:{session=L"NIGHT SESSION";break;}
	}

	int num=0;		//在对应的电影文本中把退票的那个电影院的那个位置的字母补上
	char b[100]="film";
	char *p=cat(name,b);
	wchar_t *w=read_file(p);
	int bkwd=0;		
	int i=0;
	int hang=9+(nn-1)*4+mm;		//确定行数
	while(bkwd<hang)
	{
		if(w[i]=='\n'){bkwd++;}
		i++;
	}
	int mark=i;
	wchar_t *seat=(wchar_t*)malloc(5*sizeof(wchar_t));
	do{
		memset(seat,0,5*sizeof(wchar_t));
		InputBox(seat,5,L"please enter the seat of the film you would like to get refund of and make sure it is correct !",NULL,NULL,NULL,100,150);
		if(wcscmp(seat,L"A")==0){i=i+3;w[i]=L'A';}		//和哪个字母是一样的，就更改哪个位置的值（本身就是按照顺序设置的座位编号）
		if(wcscmp(seat,L"B")==0){i=i+4;w[i]=L'B';}
		if(wcscmp(seat,L"C")==0){i=i+5;w[i]=L'C';}
		if(wcscmp(seat,L"D")==0){i=i+6;w[i]=L'D';}
		if(wcscmp(seat,L"E")==0){i=i+7;w[i]=L'E';}
		if(wcscmp(seat,L"F")==0){i=i+8;w[i]=L'F';}
		if(wcscmp(seat,L"G")==0){i=i+9;w[i]=L'G';}
		if(wcscmp(seat,L"H")==0){i=i+10;w[i]=L'H';}
		if(wcscmp(seat,L"I")==0){i=i+11;w[i]=L'I';}
		if(wcscmp(seat,L"J")==0){i=i+12;w[i]=L'J';}
		if(wcscmp(seat,L"K")==0){i=i+13;w[i]=L'K';}
		if(wcscmp(seat,L"L")==0){i=i+14;w[i]=L'L';}
		if(wcscmp(seat,L"M")==0){i=i+15;w[i]=L'M';}
		if(wcscmp(seat,L"N")==0){i=i+16;w[i]=L'N';}
		if(wcscmp(seat,L"O")==0){i=i+17;w[i]=L'O';}
		if(wcscmp(seat,L"P")==0){i=i+18;w[i]=L'P';}
		if(wcscmp(seat,L"Q")==0){i=i+19;w[i]=L'Q';}
		if(wcscmp(seat,L"R")==0){i=i+20;w[i]=L'R';}
		if(wcscmp(seat,L"S")==0){i=i+21;w[i]=L'S';}
		if(wcscmp(seat,L"T")==0){i=i+22;w[i]=L'T';}
		if(wcscmp(seat,L"U")==0){i=i+23;w[i]=L'U';}
		if(wcscmp(seat,L"V")==0){i=i+24;w[i]=L'V';}
		if(wcscmp(seat,L"W")==0){i=i+25;w[i]=L'W';}
		if(wcscmp(seat,L"X")==0){i=i+26;w[i]=L'X';}
		if(wcscmp(seat,L"Y")==0){i=i+27;w[i]=L'Y';}
	}while(mark==i);
	FILE *fp2;
	if((fp2=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//打不开文件的报错
	fwprintf(fp2,w);
	fclose(fp2);

	char bbb[100]="user";	//在用户的文本中写入退票信息
	char *pp=cat(p_user,bbb);
	FILE *fp3;
	if((fp3=fopen(pp,"a"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//打不开文件的报错
	fwprintf(fp3,L"[0/");
	fwprintf(fp3,name);
	fwprintf(fp3,L"    ");
	fwprintf(fp3,cinema);
	fwprintf(fp3,L"    ");
	fwprintf(fp3,session);
	fwprintf(fp3,L"    ");
	fwprintf(fp3,seat);
	fwprintf(fp3,L"]\n");
	fclose(fp3);

	add_history(L"[refund for tickets:");	//在history中写入用户的退票操作
	add_history(name);
	add_history(L"/");
	add_history(cinema);
	add_history(L"/");
	add_history(session);
	add_history(L"    ");
	add_history(seat);
	add_history(L"]\n");

	TCHAR WDD[]=_T("TICKET REFUND PAGE");setbkmode(TRANSPARENT);		//退票信息的显示
	outtextxy(400,100,WDD);
	TCHAR WD[]=_T("YOU HAVE SUCCESSFULLY GET REFUND FOR");
	outtextxy(250,200,WD);
	outtextxy(250,250,name);
	outtextxy(270+wcslen(name)*8,250,cinema);
	outtextxy(290+wcslen(name)*8+wcslen(cinema)*8,250,session);
	outtextxy(310+wcslen(name)*8+wcslen(cinema)*8+wcslen(session)*8,250,seat);
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);		//确认按键
	outtextxy(630,450,okkk);
	int clickb=click_button(630,450,72,16);
	closegraph();
}