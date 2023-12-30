#include "Header.h"

int me_page()	//用户的个人界面
{
	int num=0;
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("ME PAGE");setbkmode(TRANSPARENT);
	outtextxy(450, 100, title);
	TCHAR str1[]=_T("CHANGE ID");setbkmode(OPAQUE);
	outtextxy(440,200,str1);
	TCHAR str2[]=_T("CHANGE PASSWORD");
	outtextxy(420,240,str2);
	TCHAR str3[]=_T("TICKETS INFO");	
	outtextxy(430,280,str3);
	TCHAR str4[]=_T("VIP");
	outtextxy(470,320,str4);
	TCHAR str5[]=_T("PRINT FAVORITES");
	outtextxy(425,360,str5);
	TCHAR str7[]=_T("<--- GO BACK");
	outtextxy(100,480,str7);

	while(1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN)
		{
			if((m.x>(440) && m.x<512) && (m.y>200 && m.y<216))
			{
				num=1;
				add_history(L"go to <CHANGE ID>//");		//按键情况均写入history.txt中
				break;
			}
			if((m.x>(420) && m.x<540) && (m.y>240 && m.y<256))
			{
				num=2;
				add_history(L"go to <CHANGE PASSWORD>//");
				break;
			}
			if((m.x>(430) && m.x<526) && (m.y>280 && m.y<296))
			{
				num=3;
				add_history(L"go to <TICKETS>//");
				break;
			}
			if((m.x>(470) && m.x<494) && (m.y>320 && m.y<336))
			{
				num=4;
				add_history(L"go to <VIP>//");
				break;
			}
			if((m.x>(420) && m.x<540) && (m.y>360 && m.y<376))
			{
				num=5;
				add_history(L"go to <PRINT FAVORITES>//");
				break;
			}
			if((m.x>(100) && m.x<196) && (m.y>480 && m.y<496))
			{
				num=6;
				add_history(L"go back to <ME>//");
				break;
			}
		}
	}
	closegraph();
	return num;
}