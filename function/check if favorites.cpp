#include "Header.h"

int check_if_favorites(wchar_t *name)	//�ж��Ƿ��Ѿ��ղظõ�Ӱ�ĺ������Ӷ��ж�����ʾlike��ť������ʾ���ղص�����
{
	int flag=0;	//����Ƿ����ղؼ���
	int hang=0;	//����
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int bkwd=0;	//�س�������
	int i=0;
	while(bkwd<2)
	{
		i++;	
		if(w[i]=='\n'){bkwd++;}
	}
	i++;
	wchar_t *temp=(wchar_t*)malloc((wcslen(name)+1)*sizeof(wchar_t));
	while(bkwd==2)	//��ȡ���û����ı��ļ��еĵ������Ƿ���������Ӱ�����ַ������Ӷ��ж��Ƿ��ղ�
	{
		int j=0;
		for(j=0;j<wcslen(name);j++)
		{
			temp[j]=w[i+j];
		}
		temp[j]=L'\0';
		if(wcscmp(temp,name)==0){flag=1;break;}
		if(w[i]=='\n'){bkwd++;}
		i++;
	}
	return flag;
}