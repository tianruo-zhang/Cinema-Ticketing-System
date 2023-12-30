#include "Header.h"

int user_film_page()	//用户的电影信息界面
{
	int num;
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("ALL FILMS");setbkmode(TRANSPARENT);
	outtextxy(440, 100, title);
	TCHAR str1[]=_T("PRINT FILMS LIST");setbkmode(OPAQUE);
	outtextxy(415,160,str1);
	TCHAR str2[]=_T("SORT BY RATINGS");
	outtextxy(420,200,str2);
	TCHAR str3[]=_T("SORT BY NAMES");	
	outtextxy(430,240,str3);
	TCHAR str4[]=_T("SEARCH WITH CATEGORY");
	outtextxy(400,280,str4);
	TCHAR str5[]=_T("SEARCH WITH LEADING ROLES");
	outtextxy(380,320,str5);
	TCHAR str6[]=_T("DETAILS");		
	outtextxy(450,400,str6);
	TCHAR str8[]=_T("RECOMMENDATIONS");		
	outtextxy(420,360,str8);
	TCHAR str7[]=_T("<--- GO BACK");
	outtextxy(100,480,str7);

	while(1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN) 
		{
			if((m.x>(415) && m.x<543) && (m.y>160 && m.y<176))
			{
				num=1;
				add_history(L"<PRINT FILMS LIST>//");	//按键情况均写入history.txt中
				break;
			}
			if((m.x>(420) && m.x<540) && (m.y>200 && m.y<216))
			{
				num=2;
				add_history(L"<SORT BY RATINGS>//");
				break;
			}
			if((m.x>(430) && m.x<542) && (m.y>240 && m.y<256))
			{
				num=3;
				add_history(L"<SORT BY NAMES>//");
				break;
			}
			if((m.x>(400) && m.x<560) && (m.y>280 && m.y<296))
			{
				num=4;
				add_history(L"<SEARCH WITH CATEGORY>//");
				break;
			}
			if((m.x>(380) && m.x<580) && (m.y>320 && m.y<336))
			{
				num=5;
				add_history(L"<SEARCH WITH LEADING ROLES>//");
				break;
			}
			if((m.x>(420) && m.x<540) && (m.y>360 && m.y<376))
			{
				num=6;
				add_history(L"<RECOMMENDATIONS>//");
				break;
			}
			if((m.x>(450) && m.x<506) && (m.y>400 && m.y<416))
			{
				num=7;
				add_history(L"<DETAILS>//");
				break;
			}
			if((m.x>(100) && m.x<196) && (m.y>480 && m.y<496))
			{
				num=8;
				add_history(L"go back to<HOME PAGE>//");
				break;
			}
		}
	}
	closegraph();
	return num;
}