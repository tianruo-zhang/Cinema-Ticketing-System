#include "Header.h"

int login()		//launch screen�������ж��û����
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/login background.png"));
	TCHAR title[] = _T("MOVIENIZER");setbkmode(TRANSPARENT);
	outtextxy(700, 160, title);
	TCHAR choose_identity[]=_T("Please choose your identity��");
	outtextxy(540,240,choose_identity);
	TCHAR user_identity[]=_T("USER");setbkmode(OPAQUE);
	outtextxy(780,240,user_identity);
	TCHAR administer_identity[]=_T("ADMINISTER");setbkmode(OPAQUE);
	outtextxy(780,280,administer_identity); 
	int ans;
	ans=choose_button(770,830,230,260,770,870,270,300);	//ѡ�������user����administer���Ӷ����в�ͬ�ĵ�¼
	closegraph();
	if(ans==1)	//�����user
	{
		int k=user_login();
		if(k==2){wchar_t *read=new_user(0);}	//���û���˺������ע��
		user_straightly_login();	//������˺ţ�����֮ǰ�Ѿ�������ע�ᣩ������user�ĵ�¼����
	}
	if(ans==2){administer_login();}	//�����administer��Ĭ�������˺ţ�����administer�ĵ�¼����
	return ans;
}