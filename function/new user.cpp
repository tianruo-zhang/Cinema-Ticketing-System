#include "Header.h"

wchar_t *new_user(int choose)	//���û�ע�ắ�������в���choose��Ϊ�˺�����ģ�飨�����û��������룩�еĲ��ֵ���������
{
	wchar_t *ch1=(wchar_t*)malloc(sizeof(wchar_t));		//id
	wchar_t *ch2=(wchar_t*)malloc(sizeof(wchar_t));		//��һ�����������
	wchar_t *ch3=(wchar_t*)malloc(sizeof(wchar_t));		//�������������
	if(choose==0)
	{
		initgraph(960,540,SHOWCONSOLE);
		loadimage(NULL,_T("pictures/login background.png"));
		TCHAR title[] = _T("WELCOME TO MOVIENIZER !");setbkmode(TRANSPARENT);
		outtextxy(600, 100, title);
		TCHAR title0[] = _T("NOW CREATE YOUR ACCOUNT TO ENJOY !");
		outtextxy(600, 150, title0);
	}
	if((choose==0)||(choose==1))	//choose==1���ڸ��û������ĵ���
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
		for(int k=0;k<=(num-len);k++)	//ע���id�����ظ�������ظ���Ҫ����������
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
	if((choose==0)||(choose==2))	//choose==2���ڸ����봦�ĵ���
	{
		InputBox(ch2,20,L"please create a password for yourself (make sure it is no less than 8 characters !)",NULL,NULL,NULL,100,200);
		while(wcslen(ch2)<8)		//Ҫ�����볤�Ȳ�С��8���ַ�
		{
			memset(ch2,0,20*sizeof(wchar_t));
			InputBox(ch2,20,L"no-less-than-8-character password is allowed ! please reset your password !)",NULL,NULL,NULL,100,200);
		}
		InputBox(ch3,20,L"please confirm your password bu repeating it",NULL,NULL,NULL,100,200);
		while(wcscmp(ch2,ch3)!=0)		//Ҫ���ܹ���ȷȷ�����õ����룬������������
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
		FILE *fp;	//��user list��д����û�
		fp=fopen("user info.txt","a");
		fwprintf(fp,ch1);	
		fprintf(fp,"/");
		fwprintf(fp,ch2);
		fprintf(fp,"/");
		fclose(fp);
	
		TCHAR title2[] = _T("YOU HAVE SUCCESSFULLY CREATED YOUR ACCOUNT !");
		outtextxy(600, 200, title2);
		add_history(L"\n\n[new user account created]");		//ע�����д��history.txt��
		add_history(ch1);
		add_history(L"//");
		TCHAR title5[] = _T("WOULD YOU LIKE TO SPEND $100 TO BE OUR VIP TO ENJOY A 5% DISCCOUNT ?");	//ѯ���Ƿ��ΪVIP,������user info�в��������Ϣ
		outtextxy(420, 300, title5);setbkmode(OPAQUE);
		TCHAR yes[] = _T("yes");
		outtextxy(600, 350, yes);setbkmode(OPAQUE);
		TCHAR no[]=_T("no");
		outtextxy(700,350,no);

		int judge=choose_button(595,630,345,370,695,720,345,370);	//���ѡ���ΪVIP
		if(judge==1)
		{
			TCHAR title3[] = _T("YOU HAVE BECOME OUR VIP !");setbkmode(TRANSPARENT);	//���ֶ�Ӧ����
			outtextxy(600, 400, title3);
			TCHAR title4[] = _T("ENJOY A 5% OFF FOR YOUR TICKET PRICE !");
			outtextxy(600, 450, title4);
			acc=0.95;
			FILE *fp;
			fp=fopen("user info.txt","a");
			fprintf(fp,"y//\n");	//��user info.txt�ж�Ӧλ�ý���<y>���
			fclose(fp);
			wchar_t hh[]=L"become VIP//";
			add_history(hh);
		}
		else if(judge==2)	//����ΪVIP
		{
			acc=1;
			FILE *fp;
			fp=fopen("user info.txt","a");
			fprintf(fp,"n//\n");	//��user info.txt�ж�Ӧλ�ý���<y>���
			fclose(fp);
		}

		FILE *f;	//Ϊ���û��������ı��ļ�
		char b[100]="user";
		char *pp=cat(ch1,b);
		f=fopen(pp,"w");
		fwprintf(f,L"\n\n\n");	//����س���֮�������Ϣд��ʱ�ܷ��㶨λ
		fclose(f);
		TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);	//ȷ�ϰ�ť
		outtextxy(630,480,okkk);
		int clickb=click_button(630,480,72,16);
		closegraph();
	}
	if(choose==0){return NULL;}
	if(choose==1){return ch1;}		//���û���������ʱ���������õ��û���
	if(choose==2){return ch2;}		//�����봦����ʱ���������õ�����
}