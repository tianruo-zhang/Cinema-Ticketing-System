#include "Header.h"

struct film;
struct film *p_film;

int read_film_list(int judge)	//��ӡ��Ӱ�б����в���judge��ǵ��Ǵ�ӡ�ķ�ʽ
{
	p_film=(film*)malloc(sizeof(film));
	int num=0,gang_n=0;
	char p[]="film list.txt";	
	wchar_t *w=read_file(p);
	num=wcslen(w);
	int numm=0;
	for(int i=0;i<=num-3;i++)		//��ȡfilm list.txt�еĵ�Ӱ���ơ����֡��ϼ����Ļ�����Ϣ����ṹ��������
	{
		if(w[i]=='/'){gang_n++;}

		if((gang_n%4==0)&&(w[i]!='/'))
		{
			if(i!=0){i=i+1;}
			int t=0;
			while(1)
			{
				if((w[i]=='/')||(w[i]=='\n')||(w[i]=='\0')){break;}
				p_film[numm].name[t]=w[i];
				t++;
				i++;
			}
			p_film[numm].name[t]=L'\0';
			p_film[numm].bianhao=numm+1;
			i--;
		}

		if((gang_n%4==1)&&(w[i]=='/'))
		{
			float n1=0,n2=0;
			wchar_t ch1[2],ch2[2];
			ch1[0]=w[i+1];
			ch1[1]=L'\0';
			ch2[0]=w[i+3];
			ch2[1]=L'\0';
			n1=_wtof(ch1);
			n2=_wtof(ch2);
			p_film[numm].ratings=n1+n2/10.0;
			i=i+2;
		}

		if((gang_n%4==2)&&((w[i]=='y')||(w[i]=='n')))
		{
			if(w[i]=='y'){p_film[numm].if_on=1;}
			if(w[i]=='n'){p_film[numm].if_on=0;}
			numm++;
			p_film=(film*)realloc(p_film,(numm+1)*sizeof(film));
		}
	}

	int n=numm-1;
	if(judge==-1)	//administerȨ���´�ӡ��Ӱ��û���ϼܵ�Ҳ���Բ鿴
	{
		printf("\n\n\n------------------------------------------------\nThe following is the film list !\n\n");
		for(int i=0;i<=n;i++)
		{
			printf("%d : ",p_film[i].bianhao);
			wprintf(L"%s\n\n",p_film[i].name);
		}
		printf("--------------------------------------------------\n");
	}

	if(judge==0)	//���judge==0������ӡ���+��Ӱ����
	{
		printf("\n\n\n------------------------------------------------\nThe following is the film list !\n\n");
		for(int i=0;i<=n;i++)
		{
			if(p_film[i].if_on==1)
			{
				printf("%d : ",p_film[i].bianhao);
				wprintf(L"%s\n\n",p_film[i].name);
			}
		}
		printf("--------------------------------------------------\n");
	}

	if(judge==1)	//���judge==1�����ֽ���������ӡ���+��Ӱ����+����
	{
		printf("\n\n\n------------------------------------------------\nThe following is the film list sorted by ratings !\n\n");
		int gap=n+1;		//ʹ��ϣ����������ֽ�������
		while (gap>1)
		{
			gap=gap/3+1;
			for (int i=0;i<=n-gap;i++)
			{
				int end=i;
				struct film tmp=p_film[end+gap];
				while(end>=0)
				{
					if (p_film[end].ratings>tmp.ratings)
					{
						p_film[end+gap]=p_film[end];
						end=end-gap;
					}
					else
					{
						break;
					}
				}
				p_film[end+gap]=tmp;
			}
		}
		for(int j=n;j>=0;j--)
		{
			if(p_film[j].if_on==1)
			{
				printf("%d : ",p_film[j].bianhao);
				wprintf(L"%s\n",p_film[j].name);
				printf("ratings : %.1f\n\n",p_film[j].ratings);
			}
		}
		printf("\n--------------------------------------------------\n");
	}

	if(judge==2)	//���judge==2�򰴵�Ӱ���ƽ�������Ӣ��˳�򣩺��ӡ���+��Ӱ����
	{
		struct film temp;	//ʹ�����Ʋ��������˼���������
		for(int i=0;i<n;i++)
		{
			for(int j=n;j>i;j--)
			{
				if(wcscmp(p_film[j].name,p_film[j-1].name)<0)		//ʹ��wcscmp���������ַ����Ĵ�С�Ƚ�
				{
					temp=p_film[j];
					p_film[j]=p_film[j-1];
					p_film[j-1]=temp;
				}
			}
		}
		printf("\n\n\n------------------------------------------------\nThe following is the film list sorted by names !\n\n");
		for(int i=0;i<=n;i++)
		{
			if(p_film[i].if_on==1)
			{
				printf("%d : ",p_film[i].bianhao);
				wprintf(L"%s\n\n",p_film[i].name);
			}
		}
		printf("\n--------------------------------------------------\n");
	}
	//���judge��ȡ-1/0/1/2������е�Ӱ��Ϣ��ȡ�����������д�ӡ
	return n;
}