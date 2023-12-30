#include "Header.h"

wchar_t *film_name;

int read_film_detailed_info(wchar_t *pointer)	//当用户点击电影页面的details按钮时，跳转到海报页面，并且打印出电影详细信息
{
	int num=0;
	char b[100]="film";
	char *p=cat(pointer,b);
	wchar_t *w=read_file(p);
	num=wcslen(w);
	wchar_t p1[200]=L"pictures/Film/";
	wcscat(p1,pointer);
	wcscat(p1,L".png");		//渲染海报图片，并且海报上有几个按键可以进行加入收藏夹操作、购票操作、关闭海报页面操作
	initgraph(800,1200,SHOWCONSOLE);
	loadimage(NULL,p1);
	printf("\n\n\n------------------------------------------------\nThe detailed information is as follows !\n\n");		//打印电影详细信息（i遍历存储了文件信息的w数组）
	int i=0;
	printf("NAME : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	while(1)
	{
		if(w[i]!='\n'){i++;}
		if(w[i]=='\n'){break;}
	}
	i++;
	printf("DIRECTOR : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("LEADING ROLES : ");
	while(1)
	{
		if(w[i]!='\n')
		{
			if(w[i]!='/'){wprintf(L"%c",w[i]);}
			if(w[i]=='/'){wprintf(L"%s",L" & ");}
			i++;
		}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("COUNTRY : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("YEAR : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("CATEGORY : ");
	while(1)
	{
		if(w[i]!='\n')
		{
			if(w[i]!='/'){wprintf(L"%c",w[i]);}
			if(w[i]=='/'){wprintf(L"%s",L" & ");}
			i++;
		}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("ON YEAR : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("BRIEF INTRODUCTION : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	i++;
	printf("RATINGS : ");
	while(1)
	{
		if(w[i]!='\n'){wprintf(L"%c",w[i]);i++;}
		if(w[i]=='\n'){break;}
	}
	printf("\n\n");
	printf("--------------------------------------------------\n\n");
	
	int like_if=check_if_favorites(pointer);	//判断收藏与否，如果还没有加入收藏夹，则显示<like>按键，如果已经加入收藏夹，则显示已经加入收藏夹的标语
	if(like_if==1)
	{
		TCHAR title22[] = _T("ALREADY ADDED TO <FAVORITES> !");setbkmode(TRANSPARENT);
		outtextxy(300, 600, title22);
	}
	if(like_if==0)
	{
		TCHAR title[] = _T("CLICK \"LIKE\" TO ADD TO FAVORITES");setbkmode(TRANSPARENT);
		outtextxy(30, 600, title);
		TCHAR title33[] = _T("LIKE");setbkmode(OPAQUE);
		outtextxy(300, 600, title33);
	}
	TCHAR title11[] = _T("BUY TICKETS");setbkmode(OPAQUE);
	outtextxy(30, 650, title11);
	TCHAR str1[]=_T("CLOSE");setbkmode(OPAQUE);
	outtextxy(30,700,str1);

	while(1)	//海报图片上一共有3个按键，判断按了哪个按键
	{
		ExMessage m;
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN) 
		{
			if((m.x>300 && m.x<332) && (m.y>600 && m.y<616))
			{
				num=0;
				if(like_if==0)
				{
					add_to_favorites(pointer);
					TCHAR title22[] = _T("YOU HAVE ADDED IT TO YOUR <FAVORITES> !");setbkmode(TRANSPARENT);
					outtextxy(400, 600, title22);
				
					TCHAR okkk[]=_T("CONFIRM !");setbkmode(OPAQUE);
					outtextxy(700,630,okkk);
					int y=click_button(700,630,72,16);		//确认按键
					add_history(L"add ");
					add_history(pointer);
					add_history(L" to <FAVORITES>//");
					break;
				}
			}
			if((m.x>30 && m.x<118) && (m.y>650 && m.y<666))
			{
				num=1;
				add_history(L"go to <BUY TICKETS> page of ");
				add_history(pointer);
				film_name=pointer;
				add_history(L"//");
				break;
			}
			if((m.x>30 && m.x<70) && (m.y>700 && m.y<716))
			{
				num=2;
				add_history(L"close ");
				add_history(pointer);
				add_history(L" and go back to <ALL FILMS>//");
				break;
			}
		}
	}
	closegraph();
	return num;
}