#include "Header.h"

void edit_seat(wchar_t *name,wchar_t *cinema,wchar_t *session,wchar_t *seat)	//��user��Ʊ����ĵ�Ӱ�ı��е���λ��Ϣ�ĺ���
{
	int num=0;
	char b[100]="film";
	char *p=cat(name,b);
	wchar_t *w=read_file(p);
	num=wcslen(w);	//���鳤��
	int numm=_wtoi(cinema);	//�ַ���ת��Ϊ������
	int nn=_wtoi(session);
	int hang=9+(numm-1)*4+nn;	//�ҵ���Ҫ�޸ĵĶ�Ӧ��������ͨ����Ӧ�ĵ�ӰԺ���Ƽ����ƶ�
	int bkwd=0;
	int i=0;
	for(i=0;i<=num;i++)
	{
		if(w[i]=='\n'){bkwd++;}
		if(bkwd==hang){break;}
	}
	i++;
	while(w[i]!='/')
	{
		i++;
	}
	i++;
	while(1)
	{
		wchar_t cc=w[i];
		if(cc==*seat){w[i]=L' ';break;}	//�����λ�ñ���Ʊ�󣬱����λ���ַ����Ķ�Ӧλ���޸�Ϊһ���ո��ڶ�ȡ�ļ������w������ֱ���޸ģ�֮������w��д�ı���
		i++;
	}
	FILE  *fp2;
	if((fp2=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}	//�򲻿��ļ��ı���
	fwprintf(fp2,w);
	fclose(fp2);
}