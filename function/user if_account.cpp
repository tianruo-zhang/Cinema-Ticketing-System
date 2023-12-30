#include "Header.h"

int user_login()	//用户选择是否有账号的界面函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/login background.png"));
	TCHAR title[] = _T("USER LOGIN");setbkmode(TRANSPARENT);
	outtextxy(700, 100, title);
	TCHAR chooseid[] = _T("Please choose:");setbkmode(TRANSPARENT);
	outtextxy(600, 200, chooseid);
	TCHAR id[] = _T("I already have an account.");setbkmode(OPAQUE);
	outtextxy(750, 200, id);
	TCHAR password[] = _T("I have no account yet.");
	outtextxy(750, 250, password);
	int m=choose_button(740,950,190,220,740,900,240,270);
	closegraph;
	return m;
}