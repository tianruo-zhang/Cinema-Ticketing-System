#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

//����ܹ���Ϊwhile+switch�ṹ��while��Ϊ��ʵ���ڸ�ҳ���ͣ����switch��Ϊ��ʵ��ͨ�����ҳ���ϵĲ�ͬ��ť�����ú���ʵ�ֹ���/��ת������ҳ��
int main()
{
	int id=0;
	id=login();	//ѡ�����	
	int go=0;
	while(1)	
	{
		go=home_page(id);	//��ͬ��ݵĽ����а������
		switch(go)	
		{
		case 1:	//user�ĵ�Ӱ��Ϣ����		
			{
				int s=0;
				while(1)
				{
					int judge=0;
					s=user_film_page();	//��Ӱ��Ϣ�����еİ������
					switch(s)
					{
					case 1:{int read0=read_film_list(0);break;}		//��ӡ��Ӱ�б�
					case 2:{int read1=read_film_list(1);break;}		//����������
					case 3:{int read2=read_film_list(2);break;}		//����������
					case 4:{int *r1=search_with_cat(0,NULL,0);break;}		//��category�Ĺؼ��ʽ��м���
					case 5:{int *r2=search_with_roles(0,NULL,0);break;}	//��leading roles�Ĺؼ��ʽ��м���
					case 6:{recommend();break;}		//��Ӱ�Ƽ�
					case 7:	//�鿴��Ӱ��ϸ��Ϣ���棨��Ӱ�������棩
						{
							wchar_t *pp;
							int ppp=0;
							pp=film_details();	//��ǵ�Ӱ����
							while(1)
							{
								ppp=read_film_detailed_info(pp);	//��Ӱ���������еİ������
								if(ppp==0){break;}		//�����ղ�
								if(ppp==1){ticket_page(film_name,0);break;}		//��Ʊ
								if(ppp==2){break;}		//�رպ���
							}
							break;
						}
					case 8:{judge=1;break;}	//���ذ���
					}
					if(judge==1){break;}
				}
				break;
			}
		
		case 2:		//user�ĸ�����Ϣ����
			{
				int m=0;
				while(1)
				{
					int judge=0;
					m=me_page();	//������Ϣ�����еİ������
					switch(m)
					{
					case 1:{user_change_id();break;}	//����id
					case 2:{user_change_pswd();break;}	//��������
					case 3:	//Ʊ����Ϣ����
						{
							int tick=0;
							while(1)
							{
								int flag=0;
								tick=user_ticket_info_page();	//Ʊ����Ϣ����İ������
								switch(tick)
								{
								case 1:{print_ticket_info(0);break;}	//��ӡƱ����Ϣ
								case 2:{ticket_page(NULL,1);break;}	//��Ʊ
								case 3:{ticket_refund();break;}	//��Ʊ
								case 4:{flag=1;break;}	//���ذ���
								}
								if(flag==1){break;}
							}
							break;
						}
					case 4:{vip();break;}	//VIP����
					case 5:{print_favorites();break;}	//�ղؼд�ӡ
					case 6:{judge=1;break;}	//���ذ���
					}
					if(judge==1){break;}
				}
				break;
			}

		case 3:		//log out����
			{
				id=login();
				//go=home_page(id);
				break;
			}

		case 4:		//administer��Ӱ��Ϣ����
			{
				int numm=0;
				numm=read_film_list(-1);
				edit_film_info(numm);	//�����Ӱ��Ϣ���Ľ���
				break;
			}

		case 5:		//administer�û���Ϣ��ѯ����	
			{
				int ans=0;
				while(1)
				{
					int judge=0;
					ans=user_info_page();	//�û���Ϣ��ѯ�����еİ������
					switch(ans)
					{
					case 1:{print_user_list();break;}	//��ӡ�û��б�
					case 2:{print_user_history();break;}	//��ӡ�û�������ʷ
					case 3:{judge=1;break;}	//���ذ���
					}
					if(judge==1){break;}
				}
				break;
			}
		}
	}
	return 0;
}