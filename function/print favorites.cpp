#include "Header.h"

void print_favorites()	//��ӡ�û����ղؼУ��𵽲鿴�ղؼеĹ���
{
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int bkwd=0;
	int i=0;
	while(bkwd<2)	//�ҵ��ղؼ����ڵĶ�Ӧ����
	{
		i++;	
		if(w[i]=='\n'){bkwd++;}
	}
	i++;
	printf("\n\n\n------------------------------------------------\nThe following is your <FAVORITES> !\n\n");
	if(w[i]!='\n')
	{
		while(w[i]!='\n')
		{
			wchar_t tt;		//��������ַ������
			tt=w[i];
			if(tt!='/'){wprintf(&tt);}
			if(tt=='/'){wprintf(L"\n\n");}	
			i++;	
		}
	}
	else("no info !\n\n");		//��û����Ϣ���ʱ
	printf("--------------------------------------------------\n");
}