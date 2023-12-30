#include "Header.h"

void recommend()	//推荐用户可能喜欢看的电影的函数，其实就是把ta之前检索过的category和leading roles的关键词全部再检索一遍后统计相关电影的出现次数，按次数从大到小依次输出
{
	int n=read_film_list(3);	//read_film_list()函数参数填3也即只进行信息的读取而不进行打印
	int *result=(int *)malloc((n+1)*sizeof(int));
	memset(result,0,(n+1)*sizeof(int));
	printf("THE FOLLOWING ARE THE FILMS YOU MAY BE INTERSTED IN !\n\nAND THEY ARE SORTED BY LIKELIHOOD FROM THE HIGH TO THE LOW !\n\n\n");
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int i=0;
	int bkwd=0;
	int k=0;
	wchar_t *read=(wchar_t*)malloc(30*sizeof(wchar_t));		//读取需要比对的字符串，也即用户文件中ta曾今检索过的category/leading roles的关键词
	while(1)
	{
		if(w[i]==L'/')
		{
			read[k]=L'\0';
			if(bkwd==0){int *ans=search_with_cat(1,read,1);for(int u=0;u<=n;u++){result[u]=ans[u]+result[u];}}		//调用search_with_cat()函数从而读出标记了电影出现次数的数组ans，并且将ans的结果加到result数组中实现累加	
			if(bkwd==1){int *ans=search_with_roles(1,read,1);for(int u=0;u<=n;u++){result[u]=ans[u]+result[u];}}	
			read=(wchar_t*)malloc(30*sizeof(wchar_t));
			k=0;
		}
		if((w[i]!='/')&&(w[i]!='\n'))
		{
			read[k]=w[i];
			k++;
		}
		if(w[i]==L'\n'){bkwd++;}
		if(bkwd==2){break;}
		i++;
	}

	int gap=read_film_list(3);
	int max=0,m=0;
	int if_print=0;	//标记是否有输出
	while(1)	//按result大小依次输出电影，从而实现按用户喜欢电影的可能性进行排序后输出推荐内容
	{
		for(int h=0;h<=gap;h++)
		{
			if(result[h]>max){max=result[h];m=h;}
		}
		if(max==0){break;}
		wprintf(p_film[m].name);
		if_print=1;
		result[m]=0;
		printf("\n\n");
		m=0;
		max=0;
	}
	if(if_print==0){printf("no info !\n\n");}		//当没有信息进行输出时
	printf("\n\n-----------------------------------------------------------\n\n");
}