#include "Header.h"

int *search_with_roles(int wherecome,wchar_t *name,int not_print)	//使用leading roles关键词进行检索的函数，和search_with_cat()基本一样
{
	wchar_t *catt=(wchar_t*)malloc(30*sizeof(wchar_t));
	int n=0;
	int judge=0;
	n=read_film_list(3);	//resd_film_list参数填的3，只读取电影信息但不进行打印
	int *ans=(int *)malloc((n+1)*(sizeof(int)));
	memset(ans,0,(n+1)*sizeof(int));
	if(wherecome==0)
	{
		InputBox(catt,50,L"please enter the name of the actor/actress that you would like to search for",NULL,NULL,NULL,100,150);
		printf("\n\n---------------------------------------------\nRESULTS OF  ");
		wprintf(catt);
		printf("\n\n");
		char bb[100]="user";	//将查找的leading roles写入用户的文本文件，用于之后的recommendation
		char *pp=cat(p_user,bb);
		wchar_t *ww=read_file(pp);
		FILE *f;
		f=fopen(pp,"w");
		int r=0;
		int bk=0;
		while(1)
		{
			if(ww[r]=='\n'){bk++;}
			if(bk==2){break;}
			wchar_t rr;
			rr=ww[r];
			fwprintf(f,&rr);
			r++;
		}
		fwprintf(f,catt);
		fwprintf(f,L"/");
		fwprintf(f,&ww[r]);
		fclose(f);
	}
	if(wherecome==1){catt=name;}

	for(int i=0;i<=n;i++)	//查找对应电影的文本文件，如果对应行有该关键词且该电影已上架则打印输出
	{
		int num=0,hang=0;
		char b[100]="film";
		char *p=cat(p_film[i].name,b);
		wchar_t *w=read_file(p);
		num=wcslen(w);
		int k;
		for(k=0;k<=num;k++)
		{
			if(w[k]=='\n'){hang++;}
			if(hang==3){break;}
		}
		for(int s=k+1;s<=num-wcslen(catt);s++)
		{
			int j=0;
			if(w[s]=='\n'){break;}
			while(1)
			{
				if(*(catt+j)!=w[s+j]){break;}
				j++;
				if(j==wcslen(catt)){break;}
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
					ans[i]++;	//ans数组用于输出该电影出现了1次/0次，从而用于recommend模块的电影排序
					judge=1;
					break;
				}
			}
		}
	}

	if(wherecome==0)	//无对应电影时的结果输出
	{
		if(judge==0){printf("SEARCH WITH LEADING ROLES \n\nSORRY : no matching film !\n\n");}
		printf("\n-----------------------------------------------------\n\n");
	}
	return ans;
}