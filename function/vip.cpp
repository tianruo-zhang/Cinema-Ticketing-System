#include "Header.h"

void vip()	//VIP界面
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	setbkmode(TRANSPARENT);outtextxy(450,50,L"VIP PAGE");setbkmode(TRANSPARENT);

	if(acc==1)	//acc用于标记该用户是否为VIP，如果不是VIP显示如下界面
	{
		TCHAR title[] = _T("TO JOIN US AND BE THE NOBEL VIP !");
		outtextxy(200, 100, title);
		TCHAR title00[] = _T("YOU CAN ENJOY A 5% OFF FOR EVERY OF YOUR TICKETS !");
		outtextxy(200, 150, title00);
		TCHAR title0[] = _T("IT ONLY COST YOU $100 AS AN ENTRY FEE !");
		outtextxy(200, 200, title0);
		TCHAR yes[] = _T("yes");setbkmode(OPAQUE);
		outtextxy(300, 300, yes);
		TCHAR no[]=_T("no");
		outtextxy(500,300,no);

		int judge=choose_button(300,324,300,316,500,516,300,316);	//判断用户是否选择成为VIP
		if(judge==1)
		{
			TCHAR title3[] = _T("YOU HAVE BECOME OUR VIP !");setbkmode(TRANSPARENT);
			outtextxy(200, 400, title3);
			TCHAR title4[] = _T("ENJOY A 5% OFF FOR YOUR TICKET PRICE !");
			outtextxy(200, 450, title4);
			acc=0.95;
			FILE *fp;
			fp=fopen("user info.txt","a");
			fclose(fp);
			add_history(L"become VIP//");
		
			char p[]="user info.txt";	//查找该用户信息在user info.txt中所在的位置，从而更改其VIP标记
			wchar_t *w=read_file(p);
			int num=wcslen(w);
			int k=0,t=0,gang_n=0;
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
			int g;
			for(g=k+t+1;;g++)
			{
				if(w[g]==L'/'){break;}
			}
			w[g+1]=L'y';
		
			FILE *fp2;
			fp2=fopen("user info.txt","w");
			fwprintf(fp2,w);
			fclose(fp2);
			TCHAR str7[]=_T("CONFIRM !");setbkmode(OPAQUE);	//返回按钮
			outtextxy(600,480,str7);
			int go_out_of_vip_page=click_button(600,480,96,16);
		}
	}
	else    //如果已经是VIP显示的界面
	{
		TCHAR title5[] = _T("YOUR ARE OUR NOBEL VIP !");
		outtextxy(200, 200, title5);
		TCHAR title6[] = _T("ENJOY YOUR TIME IN MOVIENIZER !");
		outtextxy(200, 270, title6);
		TCHAR title7[] = _T("ENJOY YOUR 5% OFF FOR ALL YOUR TICKETS !");
		outtextxy(200, 340, title7);
		TCHAR str7[]=_T("<--- GO BACK");setbkmode(OPAQUE);	//返回按钮
		outtextxy(100,480,str7);
		int go_out_of_vip_page=click_button(100,480,96,16);
	}
	closegraph;
}