#include "Header.h"

int login()		//launch screen，用于判断用户身份
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/login background.png"));
	TCHAR title[] = _T("MOVIENIZER");setbkmode(TRANSPARENT);
	outtextxy(700, 160, title);
	TCHAR choose_identity[]=_T("Please choose your identity：");
	outtextxy(540,240,choose_identity);
	TCHAR user_identity[]=_T("USER");setbkmode(OPAQUE);
	outtextxy(780,240,user_identity);
	TCHAR administer_identity[]=_T("ADMINISTER");setbkmode(OPAQUE);
	outtextxy(780,280,administer_identity); 
	int ans;
	ans=choose_button(770,830,230,260,770,870,270,300);	//选择身份是user还是administer，从而进行不同的登录
	closegraph();
	if(ans==1)	//如果是user
	{
		int k=user_login();
		if(k==2){wchar_t *read=new_user(0);}	//如果没有账号则进行注册
		user_straightly_login();	//如果有账号（包括之前已经进行了注册），进入user的登录界面
	}
	if(ans==2){administer_login();}	//如果是administer，默认已有账号，进入administer的登录界面
	return ans;
}