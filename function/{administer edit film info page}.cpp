#include "Header.h"

void edit_film_info(int n)	//administer用于更改电影信息的界面
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	int num=0;
	int nn;
	wchar_t *edit_film;
	TCHAR title[] = _T("EDIT FILM INFO");setbkmode(TRANSPARENT);
	outtextxy(400, 120, title);
	wchar_t *ch1=(wchar_t*)malloc(sizeof(wchar_t));
	InputBox(ch1,20,L"please enter the number of the film you would like to edit/add info of",NULL,NULL,NULL,100,150);
	nn=_wtoi(ch1)-1;

	if(nn>n)	//如果输入的编号大于n，则表明新增电影
	{
		nn=n+1;
		wchar_t *name;
		name=add_new_film();
		TCHAR addd[]=_T("SUCCESSFULLY ADDED ");setbkmode(TRANSPARENT);
		outtextxy(200,250,addd);
		outtextxy(360,250,name);
		TCHAR t[]=_T("TO MOVIENIZER !");
		outtextxy((370+8*wcslen(name)),250,t);
		TCHAR tt[]=_T("YOU CAN CHECK THE INFO ON THE CONSOLE !");
		outtextxy(200,300,tt);
		TCHAR ttT[]=_T("AND DON'T FORGET TO IMPORT THE IMAGE !");
		outtextxy(200,350,ttT);
		TCHAR rrr[]=_T("COMFIRM !");setbkmode(OPAQUE);
		outtextxy(750,450,rrr);
		int clickb=0;
		while(1)
		{
			clickb=click_button(750,450,72,16);
			if(clickb==1){break;}
		}
	}

	else
	{
		edit_film=p_film[nn].name;
		printf("\n\n\n------------------------------------------------\nThe followings are the possible action names !\n\n");	//打印操作名称便于输入
		printf("change name\n\n");
		printf("change image\n\n");
		printf("change director\n\n");
		printf("change leading role\n\n");
		printf("change country\n\n");
		printf("change year\n\n");
		printf("change category\n\n");
		printf("change on year\n\n");
		printf("change introduction\n\n");
		printf("change ratiings\n\n");
		printf("change if_on\n\n");
		printf("set ticket number\n\n");
		printf("delete\n\n");
		printf("\n--------------------------------------------------\n");
		int catt=-1;
		do{
			wchar_t *ch2=(wchar_t*)malloc(sizeof(wchar_t));
			InputBox(ch2,20,L"please enter the correct action name",NULL,NULL,NULL,100,150);	//记录administer输入的操作，并且用catt变量进行标记，从而下面可以调用不同的函数
			if(wcscmp(ch2,L"change name")==0){catt=0;}
			if(wcscmp(ch2,L"change image")==0){catt=1;}
			if(wcscmp(ch2,L"change director")==0){catt=2;}
			if(wcscmp(ch2,L"change leading role")==0){catt=3;}
			if(wcscmp(ch2,L"change country")==0){catt=4;}
			if(wcscmp(ch2,L"change year")==0){catt=5;}
			if(wcscmp(ch2,L"change category")==0){catt=6;}
			if(wcscmp(ch2,L"change on year")==0){catt=7;}
			if(wcscmp(ch2,L"change introduction")==0){catt=8;}
			if(wcscmp(ch2,L"change ratings")==0){catt=9;}
			if(wcscmp(ch2,L"change if_on")==0){catt=10;}
			if(wcscmp(ch2,L"set ticket number")==0){catt=11;}
			if(wcscmp(ch2,L"delete")==0){catt=12;}
		}while(catt==-1);		//如果没有输入正确操作，则要求重新输入

		if((catt>=0)&&(catt<=9))	//如果更改的电影基本信息，调用对应函数
		{
			wchar_t *newinfo=(wchar_t*)malloc(sizeof(wchar_t));
			InputBox(newinfo,300,L"please enter new info for that category",NULL,NULL,NULL,100,150);
			wchar_t *oldinfo=edit_details(edit_film,catt,newinfo);
			TCHAR strr[]=_T("SUCCESSFULLY CHANGED FROM");setbkmode(TRANSPARENT);
			outtextxy(250,250,strr);
			outtextxy(250,300,oldinfo);
			TCHAR st[]=_T("TO");
			outtextxy(250,350,st);
			outtextxy(250,400,newinfo);
			TCHAR strrr[]=_T("COMFIRM !");setbkmode(OPAQUE);
			outtextxy(750,450,strrr);
			int clickb=0;
			while(1)
			{
				clickb=click_button(750,450,72,16);
				if(clickb==1){break;}
			}
		}		

		if(catt==10)	//更改上架与否
		{
			wchar_t *newinfo=(wchar_t*)malloc(sizeof(wchar_t));
			InputBox(newinfo,300,L"please enter new info for that category",NULL,NULL,NULL,100,150);
			wchar_t *oldinfo=edit_details(edit_film,catt,newinfo);
			TCHAR strr[]=_T("SUCCESSFULLY EDITED");setbkmode(TRANSPARENT);
			outtextxy(300,250,strr);
			TCHAR strrr[]=_T("COMFIRM !");setbkmode(OPAQUE);
			outtextxy(750,450,strrr);
			int clickb=0;
			while(1)
			{
				clickb=click_button(750,450,72,16);
				if(clickb==1){break;}
			}
		}

		if((catt>=11)&&(catt<=12))	//设置票量/删除
		{
			wchar_t *ans=edit_details(edit_film,catt,NULL);
			TCHAR strr[]=_T("SUCCESSFULLY EDITED");setbkmode(TRANSPARENT);
			outtextxy(300,250,strr);
			TCHAR strrr[]=_T("COMFIRM !");setbkmode(OPAQUE);
			outtextxy(750,450,strrr);
			int clickb=0;
			while(1)
			{
				clickb=click_button(750,450,72,16);
				if(clickb==1){break;}
			}
		}
	}
	closegraph();
}