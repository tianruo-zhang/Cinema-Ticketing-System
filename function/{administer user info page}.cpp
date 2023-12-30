#include "Header.h"

int user_info_page()	//administer查看user信息的界面
{
	int num=0;
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("USER INFO PAGE");setbkmode(TRANSPARENT);
	outtextxy(420, 120, title);
	TCHAR str1[]=_T("PRINT USER LIST");setbkmode(OPAQUE);
	outtextxy(400,200,str1);
	TCHAR str2[]=_T("PRINT USER HISTORY");
	outtextxy(400,280,str2);
	TCHAR str7[]=_T("<--- GO BACK");
	outtextxy(100,480,str7);
	while(1)
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN) 
		{
			if((m.x>(400) && m.x<520) && (m.y>200 && m.y<216)){num=1;break;}	
			if((m.x>(400) && m.x<544) && (m.y>280 && m.y<296)){num=2;break;}
			if((m.x>(100) && m.x<196) && (m.y>480 && m.y<496)){num=3;break;}
		}
	}
	closegraph();
	return num;
}