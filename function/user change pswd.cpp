#include "Header.h"

void user_change_pswd()		//用户更改password的函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("CHANGE PASSWPRD");setbkmode(TRANSPARENT);
	outtextxy(300, 100, title);
	int num=0,gang_n=0;
	char p[]="user info.txt";	
	wchar_t *w=read_file(p);
	num=wcslen(w);

	int judge=0;	//找到对应user info.txt中该用户的信息所在的位置
	int k=0,t=0;
	int len=0;
	for(k=0;k<=num-wcslen(p_user);k++)
	{
		wchar_t cc;
		if(w[k]=='/'){gang_n++;}
		if(gang_n%4==0)
		{
			for(t=0;t<wcslen(p_user);t++)
			{
				if(w[k+t]!=p_user[t]){break;}
			}
			if((t>=wcslen(p_user))&&(w[k+t]==L'/')){break;}		
		}
	}
	wchar_t str[20];	//读取原密码
	memset(str,0,20*sizeof(wchar_t));
	int m;
	for(m=k+t+1;;m++)
	{
		if(w[m]!='/'){str[m-k-t-1]=w[m];}
		else{break;}
	}
	
	while(1)	//需要用户输入原密码，只有在原密码输入正确的情况下才能进行改密码操作
	{	
		int flag=0;
		wchar_t *ch2=(wchar_t*)malloc(sizeof(wchar_t));
		InputBox(ch2,20,L"please enter your current password,and make sure it is right",NULL,NULL,NULL,100,150);	
		int s=0;
		if(wcslen(str)==wcslen(ch2))
		{
			for(s=0;s<=m-k-t-2;s++)
			{
				if(str[s]!=ch2[s]){break;}	
			}
			if(s==m-k-t-1){flag=1;}
		}
		if(flag==1){break;}
	}

	wchar_t *temp=&w[m];
	wchar_t *ch1=(wchar_t*)malloc(sizeof(wchar_t));
	ch1=new_user(2);		//调用new_user()函数并填入参数2，用以检查password是否合法
	add_history(L"change password//");
	FILE *fp;		//在user info.txt中写入新密码
	fp=fopen("user info.txt","w");
	for(int a=0;a<k+t+1;a++)
	{
		wchar_t cc;
		cc=w[a];
		fwprintf(fp,&cc);	
	}
	fwprintf(fp,ch1);
	fwprintf(fp,temp);
	fclose(fp);
	TCHAR tt[] = _T("SUCCESSFULLY CHANGED !");
	outtextxy(300, 300, tt);
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);		//确认按键
	outtextxy(630,500,okkk);
	int clickb=click_button(630,500,72,16);
	closegraph;
}
