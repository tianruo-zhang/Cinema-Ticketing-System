#include "Header.h"

int user_ticket_info_page()	//用户的票务信息界面，可以实现打印票务信息、购票、退票的功能
{
	int ans=0;
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("TICKET INFO");setbkmode(TRANSPARENT);
	outtextxy(435, 100, title);
	TCHAR str1[]=_T("PRINT TICKET HISTORY");setbkmode(OPAQUE);
	outtextxy(400,160,str1);
	TCHAR str2[]=_T("BUY TICKET");
	outtextxy(440,220,str2);
	TCHAR str3[]=_T("GET A REFUND FOR A TICKET");	
	outtextxy(380,280,str3);
	TCHAR str7[]=_T("<--- GO BACK");
	outtextxy(100,480,str7);

	while(1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN) 
		{
			if((m.x>(400) && m.x<560) && (m.y>160 && m.y<176))
			{
				ans=1;
				add_history(L"<PRINT TICKET HISTORY>//");		//按键情况均写入history.txt中
				break;
			}
			if((m.x>(440) && m.x<520) && (m.y>220 && m.y<236))
			{
				ans=2;
				add_history(L"go to <BUY TICKET>//");
				break;
			}
			if((m.x>(380) && m.x<580) && (m.y>280 && m.y<296))
			{
				ans=3;
				add_history(L"go to <GET A REFUND FOR A TICKET>//");
				break;
			}
			if((m.x>100 && m.x<196) && (m.y>480 && m.y<496))
			{
				ans=4;
				add_history(L"go back to <ALL FILMS>//");
				break;
			}
		}
	}
	closegraph();
	return ans;
}