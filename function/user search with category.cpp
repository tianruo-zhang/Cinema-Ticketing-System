#include "Header.h"

int *search_with_cat(int wherecome,wchar_t *name,int not_print)	//����category�ؼ��ʲ��ҵ�Ӱ�ĺ���������name�ǵ�Ӱ��������wherecome���ڱ����user���в��һ�����recommend�����н��е��ã��Ӷ����������ʽ
{
	int n=0;
	n=read_film_list(3);	//resd_film_list�������3��ֻ��ȡ��Ӱ��Ϣ�������д�ӡ
	wchar_t *catt;
	int judge=0;
	int *ans=(int *)malloc((n+1)*(sizeof(int)));
	memset(ans,0,(n+1)*sizeof(int));
	if(wherecome==0)	//������û�ʹ��search with category����
	{
		printf("\n\n\n------------------------------------------------\nThe followings are the possible category names !\n\n");
		printf("feature\n\nromance\n\naction\n\nmusical\n\nhistorical\n\nwar\n\nscience fiction\n\nhorror\n\nsuspensful\n\ncatastrophy\n\ncomedy\n\n");
		printf("\n--------------------------------------------------\n");
		catt=(wchar_t*)malloc(30*sizeof(wchar_t));
		InputBox(catt,30,L"please enter the one categoroy that you would like to search for",NULL,NULL,NULL,100,150);
		printf("\n\n---------------------------------------------\nRESULTS OF  ");
		wprintf(catt);
		printf("\n\n");
		char user[100]="user";	//�����ҵ�categoryд���û����ı��ļ�������֮���recommendation
		char *fn=cat(p_user,user);
		wchar_t *ww=read_file(fn);
		FILE *f;	
		f=fopen(fn,"w");
		int r=0;
		while(1)
		{
			if(ww[r]=='\n'){break;}
			wchar_t rr=ww[r];
			fwprintf(f,&rr);
			r++;
		}
		fwprintf(f,catt);
		fwprintf(f,L"/");
		fwprintf(f,&ww[r]);
		fclose(f);
	}
	if(wherecome==1){catt=name;}	//���ֻ����recommendʱ���Ҷ�Ӧ��Ӱ

	for(int i=0;i<=n;i++)	//���Ҷ�Ӧ��Ӱ���ı��ļ��������Ӧ���иùؼ����Ҹõ�Ӱ���ϼ����ӡ���
	{
		int num=0,hang=0;
		char bb[100]="film";
		char *p=cat(p_film[i].name,bb);
		wchar_t *w=read_file(p);
		num=wcslen(w);
		int k;
		for(k=0;k<=num;k++)
		{
			if(w[k]=='\n'){hang++;}
			if(hang==6){break;}
		}
		for(int s=k+1;s<num;s++)
		{
			int j=0;
			if(w[s]=='\n'){break;}
			while(1)
			{
				if(j==wcslen(catt)){break;}
				if(*(catt+j)!=w[s+j]){break;}
				j++;
			}
			if((j==wcslen(catt))&&((w[s+j]=='/')||(w[s+j]=='\n')))
			{
				if(p_film[i].if_on==1)
				{
					if(not_print==0)
					{
						wprintf(p_film[i].name);
						printf("\n\n");
					}
					ans[i]++;	//ans������������õ�Ӱ������1��/0�Σ��Ӷ�����recommendģ��ĵ�Ӱ����
					judge=1;
					break;
				}
			}
		}
	}

	if(wherecome==0)	//�޶�Ӧ��Ӱʱ�Ľ�����
	{
		if(judge==0){printf("SEARCH WITH CATEGORY \n\nSORRY : no matching film !\n\n");}
		printf("\n-----------------------------------------------------\n\n");
	}
	return ans;
}