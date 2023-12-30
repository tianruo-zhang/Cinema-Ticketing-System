#include "Header.h"

void ticket_page(wchar_t *pointer,int wherecome)	//�û���Ʊ���棬������pointer��ǵ��ǵ�Ӱ���ƣ�wherecome��ǵ��ǹ�Ʊ��ڣ��Ӷ��ж��Ƿ���Ҫ�����Ӱ����
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	if(wherecome==1)	//�������ticket info������й�Ʊ�Ļ�Ҫ�������Ӱ���ƣ������details�������Ļ�ֱ�ӻᴫ��ָ���Ӱ�����ַ�����ָ�������������һ������
	{
		int k=read_film_list(0);
		wchar_t *name=(wchar_t*)malloc(sizeof(wchar_t));
		InputBox(name,20,L"please enter the name of the film you would like to buy ticket of !",NULL,NULL,NULL,100,150);
		pointer=name;
	}

	TCHAR title[] = _T(" TICKET PAGE OF ");setbkmode(TRANSPARENT);
	outtextxy(380, 100, title);
	outtextxy(508, 100, pointer);		//��ӡ����Ӧ�ĵ�Ӱ����
	printf("\n\n\n------------------------------------------------\nThe followings are the cinemas sorted by distance with their ticket infomation !\n\n");	//���ӡ����Ӧ��ӰԺ��ʣ����λ��&ʣ����λͼ
	printf("1   STARY SKY CINEMA : \n\n");
	print_seat(pointer,1);		//���ô�ӡ��λ�ĺ�����ʹ���û����Կ�����λ�������Ʊ��
	printf("--------------------------------------------------\n\n\n");
	printf("2   MIDNIGHT CINEMA :\n\n");
	print_seat(pointer,2);
	printf("--------------------------------------------------\n\n\n");
	printf("3   PARADISE CINEMA : \n\n");
	print_seat(pointer,3);
	printf("--------------------------------------------------\n\n");

	wchar_t *cinema=(wchar_t*)malloc(sizeof(wchar_t));
	wchar_t *wd;
	int cin=0;
	do{		//���������ַ�û�ж�Ӧ��ӰԺ����Ҫ����������
		InputBox(cinema,20,L"please enter the corresponding numeber of the cinema name you would like to choose !",NULL,NULL,NULL,100,150);		//ѡ���ӰԺ
		cin=_wtoi(cinema);
		if(cin==1){TCHAR str11[]=_T("STARY SKY CINEMA");wd=L"STARY SKY CINEMA";}
		if(cin==2){TCHAR str11[]=_T("MIDNIGHT CINEMA");wd=L"MIDNIGHT CINEMA";}
		if(cin==3){TCHAR str11[]=_T("PARADISE CINEMA");wd=L"PARADISE CINEMA";}
	}while((cin!=1)&&(cin!=2)&&(cin!=3));		

	wchar_t *session=(wchar_t *)malloc(sizeof(wchar_t));
	InputBox(session,5,L"please enter the number of the session that you would like to choose ( 1 for morning / 2 for afternoon / 3 for evening / 4 for night )!",NULL,NULL,NULL,100,150);		//ѡ�񳡴�
	int flag=_wtoi(session);
	while((flag!=1)&&(flag!=2)&&(flag!=3)&&(flag!=4))		//������
	{
		memset(session,0,5*sizeof(wchar_t));
		InputBox(session,10,L"please enter the correct number of the session that you would like to choose ( morning / afternoon / evening / night are accepted )!",NULL,NULL,NULL,100,150);
		flag=_wtoi(session);
	}

	wchar_t *seat=(wchar_t*)malloc(sizeof(wchar_t));
	int judge=0;
	while(judge!=1)		//���û������Ϸ����ַ�
	{
		judge=0;
		memset(seat,0,5*sizeof(wchar_t));
		InputBox(seat,5,L"please enter the letter of the seat shown in the console that you would like to choose and make sure it is available!",NULL,NULL,NULL,100,150);		
		if(wcscmp(seat,L"A")==0){judge=1;}
		if(wcscmp(seat,L"B")==0){judge=1;}
		if(wcscmp(seat,L"C")==0){judge=1;}
		if(wcscmp(seat,L"D")==0){judge=1;}
		if(wcscmp(seat,L"E")==0){judge=1;}
		if(wcscmp(seat,L"F")==0){judge=1;}
		if(wcscmp(seat,L"G")==0){judge=1;}
		if(wcscmp(seat,L"H")==0){judge=1;}
		if(wcscmp(seat,L"I")==0){judge=1;}
		if(wcscmp(seat,L"J")==0){judge=1;}
		if(wcscmp(seat,L"K")==0){judge=1;}
		if(wcscmp(seat,L"L")==0){judge=1;}
		if(wcscmp(seat,L"M")==0){judge=1;}
		if(wcscmp(seat,L"N")==0){judge=1;}
		if(wcscmp(seat,L"O")==0){judge=1;}
		if(wcscmp(seat,L"P")==0){judge=1;}
		if(wcscmp(seat,L"Q")==0){judge=1;}
		if(wcscmp(seat,L"R")==0){judge=1;}
		if(wcscmp(seat,L"S")==0){judge=1;}
		if(wcscmp(seat,L"T")==0){judge=1;}
		if(wcscmp(seat,L"U")==0){judge=1;}
		if(wcscmp(seat,L"V")==0){judge=1;}
		if(wcscmp(seat,L"W")==0){judge=1;}
		if(wcscmp(seat,L"X")==0){judge=1;}
		if(wcscmp(seat,L"Y")==0){judge=1;}
	}

	edit_seat(pointer,cinema,session,seat);	//���ú������ļ����޸������λ��Ϣ

	switch(_wtoi(session))		//sessionת��Ϊ��Ӧ������Ϣ����
	{
	case 1:{session=L"MORNING SESSION";break;}
	case 2:{session=L"AFTERNOON SESSION";break;}
	case 3:{session=L"EVENING SESSION";break;}
	case 4:{session=L"NIGHT SESSION";break;}
	}

	TCHAR strr[]=_T("CHECK YOUR TICKET :");setbkmode(TRANSPARENT);
	outtextxy(250,220,strr);	//��ʾ��Ʊ��Ϣ
	outtextxy(250,280,wd);
	outtextxy(270+8*wcslen(wd),280,session);
	outtextxy(290+8*wcslen(wd)+8*wcslen(session),280,seat);
	outtextxy(310+8*wcslen(wd)+8*wcslen(seat)+8*wcslen(session),280,pointer);

	if(acc!=1)	//�����VIP����������һ�����Ż�
	{
		TCHAR vipw[]=_T("AS OUR NOBEL VIP MEMBER , ENJOY A 5% OFF FOR YOUR TICKET PRICE !");
		outtextxy(250,380,vipw);
	}
	TCHAR strrr[]=_T("COMFIRM !");setbkmode(OPAQUE);	//ȷ�ϰ���
	outtextxy(700,480,strrr);
	int clickb=click_button(700,480,72,16);
	add_history(L"[buy ticket :");		//��history��д����û��Ĺ�Ʊ����
	add_history(pointer);
	add_history(L"  ");
	add_history(wd);
	add_history(L"  ");
	add_history(session);
	add_history(L"  ");
	add_history(seat);
	add_history(L"]");

	char b[100]="user";		//��user���ı��ļ���д��ù�Ʊ��Ϣ
	char *p=cat(p_user,b);
	FILE *fp;
	if((fp=fopen(p,"a"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//�ļ��򲻿��ı���
	fwprintf(fp,L"[1/");		//ʹ��1��ǹ���
	fwprintf(fp,pointer);
	fwprintf(fp,L"    ");
	fwprintf(fp,wd);
	fwprintf(fp,L"    ");
	fwprintf(fp,session);
	fwprintf(fp,L"    ");
	fwprintf(fp,seat);
	fwprintf(fp,L"]\n");
	fclose(fp);
	closegraph();
}