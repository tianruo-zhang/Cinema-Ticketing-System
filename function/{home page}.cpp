#include "Header.h"

int home_page(int n)	//系统主界面，其中n=1为user所见界面，n=2为administer所见界面	
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("MOVIENIZER HOME PAGE");setbkmode(TRANSPARENT);
	outtextxy(400, 120, title);
	if(n==1)
	{
		TCHAR str1[]=_T("ALL FILMS");setbkmode(OPAQUE);
		outtextxy(440,220,str1);
		TCHAR str3[]=_T("ME PAGE");		
		outtextxy(450,280,str3);
		TCHAR str4[]=_T("LOG OUT");
		outtextxy(100,470,str4);
	}
	if(n==2)
	{
		TCHAR str5[]=_T("FILM INFO");setbkmode(OPAQUE);
		outtextxy(440,220,str5);
		TCHAR str6[]=_T("USER INFO");		
		outtextxy(440,280,str6);
		TCHAR str7[]=_T("LOG OUT");
		outtextxy(100,470,str7);
		
	}

	int num=0;
	while(1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN)
		{
			if(n==1)
			{
				if((m.x>(440) && m.x<512) && (m.y>220 && m.y<236))
				{
					num=1;		
					add_history(L"go to <ALL FILMS>//");	//按键情况均写入history.txt中
					break;
				}
				if((m.x>(450) && m.x<506) && (m.y>280 && m.y<296))
				{
					num=2;
					add_history(L"go to <ME PAGE>//");
					break;
				}
			}
			if((m.x>(100) && m.x<156) && (m.y>470 && m.y<486))
			{
				num=3;
				if(n==1)
				{
					add_history(L"log out//\n\n");
				}
				break;
			}
			if(n==2)
			{
				if((m.x>(440) && m.x<512) && (m.y>220 && m.y<236))
				{
					num=4;break;
				}
				if((m.x>(440) && m.x<512) && (m.y>280 && m.y<296))
				{
					num=5;break;
				}
			}
		}
	}
	closegraph();
	return num;
}
