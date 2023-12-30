#include "Header.h"

void administer_login()		//administer登录函数，默认管理员没有注册选项
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/login background.png"));
	TCHAR title[] = _T("ADMINISTER-LOGIN");setbkmode(TRANSPARENT);
	outtextxy(600, 100, title);
	wchar_t str1[20];memset(str1,0,20*sizeof(wchar_t));
	wchar_t str2[20];memset(str2,0,20*sizeof(wchar_t));
	wchar_t str3[20];memset(str3,0,20*sizeof(wchar_t));
	int num=0;
	char p[]="administer info.txt";		
	wchar_t *w=read_file(p);
	num=wcslen(w);
	int len;
	wchar_t *wp;
	int judge=0;
	int k,t;
	InputBox(str1,20,L"administer id",NULL,NULL,NULL,100,150);
	while(1)		//查找输入的id，如果存在则记下对应id的密码信息，如果不存在报错要求重新输入
	{
		len=wcslen(str1);
		wp=str1;
		for(k=0;k<=(num-len);k++)	//查找输入的id是否有效
		{
			if(((k>0)&&(w[k-1]==L'\n'))|(k==0))
			{
				for(t=0;t<len;t++)
				{
					if(w[k+t]!=*(wp+t)){break;}
				}
				if((t>=len)&&(w[k+t]==L'/')){judge=1;break;}
			}
		}
		if(judge==1)
		{
			int m=0;
			for(int s=k+len+1;;s++)
			{
				if(w[s]=='/'){break;}
				str3[m]=w[s];	//在该过程中记录密码，用于之后的比对
				m++;
			}
			str3[m]=L'\0';
			break;
		}
		if(judge==0){memset(str1,0,20*sizeof(wchar_t));memset(str3,0,20*sizeof(wchar_t));InputBox(str1,20,L"please enter valid administer id !",NULL,NULL,NULL,100,150);}
	}

	InputBox(str2,20,L"administer password",NULL,NULL,NULL,100,200);
	while(1)	//验证密码是否正确，如不正确要求重新输入
	{
		int a=0;
		for(a=0;a<=19;a++)
		{
			if(str2[a]!=str3[a]){break;}
		}
		if(a<20){memset(str2,0,len*sizeof(wchar_t));InputBox(str2,20,L"please enter correct administer password !",NULL,NULL,NULL,100,200);}
		if(a>=20){break;}
	}

	TCHAR suc[] = _T("SUCCESSFULLY LOGGED IN !");
	outtextxy(600, 200, suc);
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);	//确认按钮
	outtextxy(630,350,okkk);
	int kk=click_button(630,350,75,16);
	closegraph();
}