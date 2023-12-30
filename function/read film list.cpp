#include "Header.h"

struct film;
struct film *p_film;

int read_film_list(int judge)	//打印电影列表，其中参数judge标记的是打印的方式
{
	p_film=(film*)malloc(sizeof(film));
	int num=0,gang_n=0;
	char p[]="film list.txt";	
	wchar_t *w=read_file(p);
	num=wcslen(w);
	int numm=0;
	for(int i=0;i<=num-3;i++)		//读取film list.txt中的电影名称、评分、上架与否的基本信息存入结构体数组中
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
	if(judge==-1)	//administer权限下打印电影，没有上架的也可以查看
	{
		printf("\n\n\n------------------------------------------------\nThe following is the film list !\n\n");
		for(int i=0;i<=n;i++)
		{
			printf("%d : ",p_film[i].bianhao);
			wprintf(L"%s\n\n",p_film[i].name);
		}
		printf("--------------------------------------------------\n");
	}

	if(judge==0)	//如果judge==0仅仅打印编号+电影名称
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

	if(judge==1)	//如果judge==1则按评分进行排序后打印编号+电影名称+评分
	{
		printf("\n\n\n------------------------------------------------\nThe following is the film list sorted by ratings !\n\n");
		int gap=n+1;		//使用希尔排序对评分进行排序
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

	if(judge==2)	//如果judge==2则按电影名称进行排序（英文顺序）后打印编号+电影名称
	{
		struct film temp;	//使用类似插入排序的思想进行排序
		for(int i=0;i<n;i++)
		{
			for(int j=n;j>i;j--)
			{
				if(wcscmp(p_film[j].name,p_film[j-1].name)<0)		//使用wcscmp函数进行字符串的大小比较
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
	//如果judge不取-1/0/1/2，则进行电影信息读取操作，不进行打印
	return n;
}