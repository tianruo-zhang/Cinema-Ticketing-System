#include "Header.h"

void print_seat(wchar_t *point,int numm)	//��ӡ��Ӱ��λ�ĺ���
{
	int num=0;
	char b[100]="film";
	char *p=cat(point,b);
	wchar_t *w=read_file(p);
	num=wcslen(w);
	int hang=(numm-1)*4+10;	//�ҵ���Ӱ��Ϣ�ж�Ӧ��ӰԺ��������numm��ӰԺ��ţ�hang��Ŀ������
	int bkwd=0;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(w[i]=='\n'){bkwd++;}
		if(bkwd==hang){break;}
	}
	i++;
	while(hang<numm*4+10)	//��ѭ�����ӡ������ӰԺ�ĸ������ε���λ��Ϣ
	{
		while(w[i]!='/')
		{
			i++;
		}
		i++;
		int sum=0;	//���ڴ�ӡʱ�Ļ��в���
		int seat=0;		//��ӰԺ��Ʊ������
		switch(hang-(numm-1)*4-10)
		{
		case 0:{printf("\nMORNING SESSION:\n\n");break;}
		case 1:{printf("\nAFTERNOON SESSION:\n\n");break;}
		case 2:{printf("\nEVENING SESSION:\n\n");break;}
		case 3:{printf("\nNIGHT:\n\n");break;}
		}
		while(w[i]!='\n')		//���յ�ӰԺʵ����λ���ִ�ӡ��ʣ����λ���
		{
			wchar_t c=w[i];
			if((c>=L'A')&&(c<='Z')){seat++;}
			wprintf(L"%c",c);
			printf("     ");
			sum++;
			i++;
			if(sum%5==0){printf("\n\n\n");}
		}
		printf("%d SEAT(S) REMAINED !\n\n",seat);	//��������Ʊ��������user�鿴
		i++;
		hang++;
	}
}