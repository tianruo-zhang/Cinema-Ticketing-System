#include "Header.h"

void print_user_list()	//��ӡ�û��б�
{
	int num=0;
	char p[]="user info.txt";	
	wchar_t *w=read_file(p);
	num=wcslen(w);
	printf("\n\n\n------------------------------------------------\nThe following is the user list!\n\n");
	for(int i=0;i<=num;i++)
	{
		if((i==0)||(w[i-1]=='\n'))
		{
			while((w[i]!='/')&&(i<=num))	//ֻ��ӡ��user��id��Ϣ��������Ϣ�����д�ӡ
			{
				wprintf(L"%c",w[i]);
				i++;
			}
			printf("\n");
		}
	}
	printf("--------------------------------------------------\n");
}