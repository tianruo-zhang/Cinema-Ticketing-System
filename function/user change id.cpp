#include "Header.h"

void user_change_id()	//用户更改id的函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("CHANGE ID");setbkmode(TRANSPARENT);
	outtextxy(400, 100, title);
	int num=0,gang_n=0;
	char p[]="user info.txt";	
	wchar_t *w=read_file(p);
	num=wcslen(w);
	wchar_t *oldname=p_user;		
	int judge=0;
	
	int k=0,t=0;	//读出原id在user info.txt中的位置便于之后更改
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
	wchar_t *temp=&w[k+wcslen(p_user)];
	wchar_t *ch1=(wchar_t*)malloc(sizeof(wchar_t));
	ch1=new_user(1);		//调用new_user()函数，并填入参数1，从而可以实现检查id是否合法的功能
	p_user=ch1;             

	add_history(L"change id to--->");	//在history中记录用户更改id的操作信息
	add_history(ch1);
	add_history(L"//\n");
	add_history(ch1);
	add_history(L":id changed// ");

	FILE *fp2=fopen("user info.txt","w");	//重写user info.txt，将对应id进行替换
	for(int a=0;a<k;a++)
	{
		wchar_t cc;
		cc=w[a];
		fwprintf(fp2,&cc);	
	}
	fwprintf(fp2,ch1);
	fwprintf(fp2,temp);
	fclose(fp2);
	
	char mm[100]="user";	//对用户自己的文本文件进行更名操作，通过复制原文本内容再写入新文件名文件中来实现
	char *new_file_name=cat(p_user,mm);			
	char mmm[100]="user";
	char *old_file_name=cat(oldname,mmm);		
	wchar_t *ans=read_file(old_file_name);		
	FILE *f;
	f=fopen(new_file_name,"w");
	fwprintf(f,ans);
	int d=remove(old_file_name);
	fclose(f);

	TCHAR tt[] = _T("SUCCESSFULLY CHANGED !");
	outtextxy(300, 300, tt);
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);		//确认按键
	outtextxy(630,500,okkk);
	int clickb=click_button(630,500,72,16);
	closegraph;
}
