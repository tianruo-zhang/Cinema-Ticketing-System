#include "Header.h"

wchar_t *new_user(int choose)	//新用户注册函数，其中参数choose是为了和其他模块（更改用户名和密码）中的部分调用相区别
{
	wchar_t *ch1=(wchar_t*)malloc(sizeof(wchar_t));		//id
	wchar_t *ch2=(wchar_t*)malloc(sizeof(wchar_t));		//第一次输入的密码
	wchar_t *ch3=(wchar_t*)malloc(sizeof(wchar_t));		//二次输入的密码
	if(choose==0)
	{
		initgraph(960,540,SHOWCONSOLE);
		loadimage(NULL,_T("pictures/login background.png"));
		TCHAR title[] = _T("WELCOME TO MOVIENIZER !");setbkmode(TRANSPARENT);
		outtextxy(600, 100, title);
		TCHAR title0[] = _T("NOW CREATE YOUR ACCOUNT TO ENJOY !");
		outtextxy(600, 150, title0);
	}
	if((choose==0)||(choose==1))	//choose==1是在改用户名处的调用
	{
		InputBox(ch1,30,L"please create a user id for yourself (less than 20 characters !)",NULL,NULL,NULL,100,150);	
		int judge=0;
		while(wcslen(ch1)>20)
		{
			memset(ch1,0,30*sizeof(wchar_t));
			InputBox(ch1,30,L"no more than 20 characters is allowed ! please reset your id !",NULL,NULL,NULL,100,150);	
		}
		wchar_t *w=read_file("user info.txt");
		int num=wcslen(w);
		wchar_t *wp=ch1;
		int len=wcslen(ch1);
		for(int k=0;k<=(num-len);k++)	//注册的id不能重复，如果重复了要求重新输入
		{
			if(((k>0)&&(w[k-1]==L'\n'))|(k==0))
			{
				int t=0;
				for(t=0;t<len;t++)
				{
					if(w[k+t]!=*(wp+t)){break;}
				}
				if((t>=len)&&(w[k+t]==L'/')){judge=1;break;}
			}
		}
		while(judge==1)
		{
			memset(ch1,0,30*sizeof(wchar_t));
			judge=0;
			InputBox(ch1,30,L"this id has been registered before , please choose another one !",NULL,NULL,NULL,100,150);	
			while(wcslen(ch1)>20)
			{
				memset(ch1,0,30*sizeof(wchar_t));
				InputBox(ch1,30,L"no more than 20 characters is allowed ! please reset your id !",NULL,NULL,NULL,100,150);	
			}
			wchar_t *w=read_file("user info.txt");
			int num=wcslen(w);
			wchar_t *wp=ch1;
			int len=wcslen(ch1);
			for(int k=0;k<=(num-len);k++)	
			{
				if(((k>0)&&(w[k-1]==L'\n'))|(k==0))
				{
					int t=0;
					for(t=0;t<len;t++)
					{
						if(w[k+t]!=*(wp+t)){break;}
					}
					if((t>=len)&&(w[k+t]==L'/')){judge=1;break;}
				}
			}
		}
	}
	if((choose==0)||(choose==2))	//choose==2是在改密码处的调用
	{
		InputBox(ch2,20,L"please create a password for yourself (make sure it is no less than 8 characters !)",NULL,NULL,NULL,100,200);
		while(wcslen(ch2)<8)		//要求密码长度不小于8个字符
		{
			memset(ch2,0,20*sizeof(wchar_t));
			InputBox(ch2,20,L"no-less-than-8-character password is allowed ! please reset your password !)",NULL,NULL,NULL,100,200);
		}
		InputBox(ch3,20,L"please confirm your password bu repeating it",NULL,NULL,NULL,100,200);
		while(wcscmp(ch2,ch3)!=0)		//要求能够正确确认设置的密码，因此需二次输入
		{
			memset(ch2,0,20*sizeof(wchar_t));
			memset(ch3,0,20*sizeof(wchar_t));
			InputBox(ch2,20,L"not consistent!reset your password",NULL,NULL,NULL,100,200);
			while(wcslen(ch2)<8)
			{
				memset(ch2,0,20*sizeof(wchar_t));
				InputBox(ch2,20,L"no-less-than-8-character is allowed ! please reset your password !)",NULL,NULL,NULL,100,200);
			}
			InputBox(ch3,20,L"confirm your password",NULL,NULL,NULL,100,200);
		}
	}
	
	if(choose==0)
	{
		FILE *fp;	//在user list中写入该用户
		fp=fopen("user info.txt","a");
		fwprintf(fp,ch1);	
		fprintf(fp,"/");
		fwprintf(fp,ch2);
		fprintf(fp,"/");
		fclose(fp);
	
		TCHAR title2[] = _T("YOU HAVE SUCCESSFULLY CREATED YOUR ACCOUNT !");
		outtextxy(600, 200, title2);
		add_history(L"\n\n[new user account created]");		//注册情况写入history.txt中
		add_history(ch1);
		add_history(L"//");
		TCHAR title5[] = _T("WOULD YOU LIKE TO SPEND $100 TO BE OUR VIP TO ENJOY A 5% DISCCOUNT ?");	//询问是否成为VIP,并且在user info中补充相关信息
		outtextxy(420, 300, title5);setbkmode(OPAQUE);
		TCHAR yes[] = _T("yes");
		outtextxy(600, 350, yes);setbkmode(OPAQUE);
		TCHAR no[]=_T("no");
		outtextxy(700,350,no);

		int judge=choose_button(595,630,345,370,695,720,345,370);	//如果选择成为VIP
		if(judge==1)
		{
			TCHAR title3[] = _T("YOU HAVE BECOME OUR VIP !");setbkmode(TRANSPARENT);	//出现对应文字
			outtextxy(600, 400, title3);
			TCHAR title4[] = _T("ENJOY A 5% OFF FOR YOUR TICKET PRICE !");
			outtextxy(600, 450, title4);
			acc=0.95;
			FILE *fp;
			fp=fopen("user info.txt","a");
			fprintf(fp,"y//\n");	//在user info.txt中对应位置进行<y>标记
			fclose(fp);
			wchar_t hh[]=L"become VIP//";
			add_history(hh);
		}
		else if(judge==2)	//不成为VIP
		{
			acc=1;
			FILE *fp;
			fp=fopen("user info.txt","a");
			fprintf(fp,"n//\n");	//在user info.txt中对应位置进行<y>标记
			fclose(fp);
		}

		FILE *f;	//为新用户创建其文本文件
		char b[100]="user";
		char *pp=cat(ch1,b);
		f=fopen(pp,"w");
		fwprintf(f,L"\n\n\n");	//敲入回车，之后相关信息写入时能方便定位
		fclose(f);
		TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);	//确认按钮
		outtextxy(630,480,okkk);
		int clickb=click_button(630,480,72,16);
		closegraph();
	}
	if(choose==0){return NULL;}
	if(choose==1){return ch1;}		//改用户名处调用时返回新设置的用户名
	if(choose==2){return ch2;}		//改密码处调用时返回新设置的密码
}