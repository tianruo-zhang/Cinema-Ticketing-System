#include "Header.h"

void recommend()	//�Ƽ��û�����ϲ�����ĵ�Ӱ�ĺ�������ʵ���ǰ�ta֮ǰ��������category��leading roles�Ĺؼ���ȫ���ټ���һ���ͳ����ص�Ӱ�ĳ��ִ������������Ӵ�С�������
{
	int n=read_film_list(3);	//read_film_list()����������3Ҳ��ֻ������Ϣ�Ķ�ȡ�������д�ӡ
	int *result=(int *)malloc((n+1)*sizeof(int));
	memset(result,0,(n+1)*sizeof(int));
	printf("THE FOLLOWING ARE THE FILMS YOU MAY BE INTERSTED IN !\n\nAND THEY ARE SORTED BY LIKELIHOOD FROM THE HIGH TO THE LOW !\n\n\n");
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int i=0;
	int bkwd=0;
	int k=0;
	wchar_t *read=(wchar_t*)malloc(30*sizeof(wchar_t));		//��ȡ��Ҫ�ȶԵ��ַ�����Ҳ���û��ļ���ta�����������category/leading roles�Ĺؼ���
	while(1)
	{
		if(w[i]==L'/')
		{
			read[k]=L'\0';
			if(bkwd==0){int *ans=search_with_cat(1,read,1);for(int u=0;u<=n;u++){result[u]=ans[u]+result[u];}}		//����search_with_cat()�����Ӷ���������˵�Ӱ���ִ���������ans�����ҽ�ans�Ľ���ӵ�result������ʵ���ۼ�	
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
	int if_print=0;	//����Ƿ������
	while(1)	//��result��С���������Ӱ���Ӷ�ʵ�ְ��û�ϲ����Ӱ�Ŀ����Խ������������Ƽ�����
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
	if(if_print==0){printf("no info !\n\n");}		//��û����Ϣ�������ʱ
	printf("\n\n-----------------------------------------------------------\n\n");
}