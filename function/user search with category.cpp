#include "Header.h"

int *search_with_cat(int wherecome,wchar_t *name,int not_print)	//用于category关键词查找电影的函数，其中name是电影名参数，wherecome用于标记是user进行查找还是在recommend函数中进行调用，从而决定输出方式
{
	int n=0;
	n=read_film_list(3);	//resd_film_list参数填的3，只读取电影信息但不进行打印
	wchar_t *catt;
	int judge=0;
	int *ans=(int *)malloc((n+1)*(sizeof(int)));
	memset(ans,0,(n+1)*sizeof(int));
	if(wherecome==0)	//如果是用户使用search with category功能
	{
		printf("\n\n\n------------------------------------------------\nThe followings are the possible category names !\n\n");
		printf("feature\n\nromance\n\naction\n\nmusical\n\nhistorical\n\nwar\n\nscience fiction\n\nhorror\n\nsuspensful\n\ncatastrophy\n\ncomedy\n\n");
		printf("\n--------------------------------------------------\n");
		catt=(wchar_t*)malloc(30*sizeof(wchar_t));
		InputBox(catt,30,L"please enter the one categoroy that you would like to search for",NULL,NULL,NULL,100,150);
		printf("\n\n---------------------------------------------\nRESULTS OF  ");
		wprintf(catt);
		printf("\n\n");
		char user[100]="user";	//将查找的category写入用户的文本文件，用于之后的recommendation
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
	if(wherecome==1){catt=name;}	//如果只是在recommend时查找对应电影

	for(int i=0;i<=n;i++)	//查找对应电影的文本文件，如果对应行有该关键词且该电影已上架则打印输出
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
					ans[i]++;	//ans数组用于输出该电影出现了1次/0次，从而用于recommend模块的电影排序
					judge=1;
					break;
				}
			}
		}
	}

	if(wherecome==0)	//无对应电影时的结果输出
	{
		if(judge==0){printf("SEARCH WITH CATEGORY \n\nSORRY : no matching film !\n\n");}
		printf("\n-----------------------------------------------------\n\n");
	}
	return ans;
}