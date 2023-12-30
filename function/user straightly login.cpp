#include "Header.h"

float acc=0;
wchar_t *p_user=(wchar_t*)malloc(20*(sizeof(wchar_t)));

void user_straightly_login()	//用户登录函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/login background.png"));
	TCHAR title[] = _T("USER LOGIN");setbkmode(TRANSPARENT);
	outtextxy(600, 100, title);
	wchar_t str2[20];memset(str2,0,20*sizeof(wchar_t));
	wchar_t str3[20];memset(str3,0,20*sizeof(wchar_t));
	int num=0,gang_n=0,xuhao=0,n=0;
	char p[]="user info.txt";	
	int ch;
	wchar_t *w=read_file(p);
	num=wcslen(w);
	
	int length=0;
	wchar_t *wp;
	int judge=0;
	int k,t;
	InputBox(p_user,20,L"user id",NULL,NULL,NULL,100,150);
	while(1)
	{
		length=wcslen(p_user);
		wp=p_user;
		for(k=0;k<=(num-length);k++)	//查找输入的id是否有效
		{
			if(((k>0)&&(w[k-1]=='\n'))|(k==0))
			{
				for(t=0;t<length;t++)
				{
					if(w[k+t]!=*(wp+t)){break;}
				}
				if((t>=length)&&(w[k+t]=='/')){judge=1;break;}
			}
		}

		if(judge==1)
		{
			int m=0;
			for(int s=k+wcslen(p_user)+1;;s++)
			{
				if(w[s]=='/')
				{
					if(w[s+1]=='y'){acc=0.95;}
					if(w[s+1]=='n'){acc=1;}
					break;
				}
				str3[m]=w[s];	//在该过程中记录用户的密码，用于之后的比对
				m++;	
			}
			str3[m]=L'\0';
			break;
		}
		else{p_user=(wchar_t*)malloc(20*sizeof(wchar_t));memset(str3,0,20*sizeof(wchar_t));InputBox(p_user,20,L"please enter valid user id !",NULL,NULL,NULL,100,150);}	//如果无效则要求重新输入
	}

	InputBox(str2,20,L"user password",NULL,NULL,NULL,100,200);
	while(1)	//验证密码是否正确，如不正确要求重新输入
	{
		int a=0;
		for(a=0;a<=19;a++)
		{
			if(str2[a]!=str3[a]){break;}
		}
		if(a<=wcslen(str3)){memset(str2,0,wcslen(p_user)*sizeof(wchar_t));InputBox(str2,20,L"please enter correct user password !",NULL,NULL,NULL,100,200);}
		else{break;}
	}

	TCHAR suc[] = _T("SUCCESSFULLY LOGGED IN !");
	outtextxy(600, 300, suc);
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);
	outtextxy(630,350,okkk);
	add_history(L"\n\n");			//登录情况写入history.txt中
	add_history(p_user);
	add_history(L":log in//");
	int s=click_button(630,350,75,16);
	closegraph();
}