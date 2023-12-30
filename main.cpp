#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

//整体架构均为while+switch结构，while是为了实现在该页面的停留，switch是为了实现通过点击页面上的不同按钮来调用函数实现功能/跳转至其他页面
int main()
{
	int id=0;
	id=login();	//选择身份	
	int go=0;
	while(1)	
	{
		go=home_page(id);	//不同身份的界面中按键情况
		switch(go)	
		{
		case 1:	//user的电影信息界面		
			{
				int s=0;
				while(1)
				{
					int judge=0;
					s=user_film_page();	//电影信息界面中的按键情况
					switch(s)
					{
					case 1:{int read0=read_film_list(0);break;}		//打印电影列表
					case 2:{int read1=read_film_list(1);break;}		//按评分排序
					case 3:{int read2=read_film_list(2);break;}		//按名称排序
					case 4:{int *r1=search_with_cat(0,NULL,0);break;}		//按category的关键词进行检索
					case 5:{int *r2=search_with_roles(0,NULL,0);break;}	//按leading roles的关键词进行检索
					case 6:{recommend();break;}		//电影推荐
					case 7:	//查看电影详细信息界面（电影海报界面）
						{
							wchar_t *pp;
							int ppp=0;
							pp=film_details();	//标记电影名称
							while(1)
							{
								ppp=read_film_detailed_info(pp);	//电影海报界面中的按键情况
								if(ppp==0){break;}		//加入收藏
								if(ppp==1){ticket_page(film_name,0);break;}		//购票
								if(ppp==2){break;}		//关闭海报
							}
							break;
						}
					case 8:{judge=1;break;}	//返回按键
					}
					if(judge==1){break;}
				}
				break;
			}
		
		case 2:		//user的个人信息界面
			{
				int m=0;
				while(1)
				{
					int judge=0;
					m=me_page();	//个人信息界面中的按键情况
					switch(m)
					{
					case 1:{user_change_id();break;}	//更改id
					case 2:{user_change_pswd();break;}	//更改密码
					case 3:	//票务信息界面
						{
							int tick=0;
							while(1)
							{
								int flag=0;
								tick=user_ticket_info_page();	//票务信息界面的按键情况
								switch(tick)
								{
								case 1:{print_ticket_info(0);break;}	//打印票务信息
								case 2:{ticket_page(NULL,1);break;}	//购票
								case 3:{ticket_refund();break;}	//退票
								case 4:{flag=1;break;}	//返回按键
								}
								if(flag==1){break;}
							}
							break;
						}
					case 4:{vip();break;}	//VIP界面
					case 5:{print_favorites();break;}	//收藏夹打印
					case 6:{judge=1;break;}	//返回按键
					}
					if(judge==1){break;}
				}
				break;
			}

		case 3:		//log out按键
			{
				id=login();
				//go=home_page(id);
				break;
			}

		case 4:		//administer电影信息界面
			{
				int numm=0;
				numm=read_film_list(-1);
				edit_film_info(numm);	//进入电影信息更改界面
				break;
			}

		case 5:		//administer用户信息查询界面	
			{
				int ans=0;
				while(1)
				{
					int judge=0;
					ans=user_info_page();	//用户信息查询界面中的按键情况
					switch(ans)
					{
					case 1:{print_user_list();break;}	//打印用户列表
					case 2:{print_user_history();break;}	//打印用户操作历史
					case 3:{judge=1;break;}	//返回按键
					}
					if(judge==1){break;}
				}
				break;
			}
		}
	}
	return 0;
}