#include "Header.h"

void user_change_id()	//�û�����id�ĺ���
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
	
	int k=0,t=0;	//����ԭid��user info.txt�е�λ�ñ���֮�����
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
	ch1=new_user(1);		//����new_user()���������������1���Ӷ�����ʵ�ּ��id�Ƿ�Ϸ��Ĺ���
	p_user=ch1;             

	add_history(L"change id to--->");	//��history�м�¼�û�����id�Ĳ�����Ϣ
	add_history(ch1);
	add_history(L"//\n");
	add_history(ch1);
	add_history(L":id changed// ");

	FILE *fp2=fopen("user info.txt","w");	//��дuser info.txt������Ӧid�����滻
	for(int a=0;a<k;a++)
	{
		wchar_t cc;
		cc=w[a];
		fwprintf(fp2,&cc);	
	}
	fwprintf(fp2,ch1);
	fwprintf(fp2,temp);
	fclose(fp2);
	
	char mm[100]="user";	//���û��Լ����ı��ļ����и���������ͨ������ԭ�ı�������д�����ļ����ļ�����ʵ��
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
	TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);		//ȷ�ϰ���
	outtextxy(630,500,okkk);
	int clickb=click_button(630,500,72,16);
	closegraph;
}
