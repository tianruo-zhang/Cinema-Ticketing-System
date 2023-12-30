#include "Header.h"

void print_ticket_info(int wherecome)	//打印用户的票务信息，其中wherecome用于标记调用位置，wherecome==0是直接打印user文本中存储的票务信息，wherecome==1是当user想要进行退票操作时打印出可以进行退票操作的票务信息
{
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int sum=wcslen(w);
	int if_ticket=0;
	if(wherecome==0)	//仅仅是打印票务信息
	{
		int i=0;
		while(1)
		{
			i++;
			if(w[i]==L'['){break;}
			if(w[i+1]=='\0'){printf("no ticket info !\n\n");if_ticket=1;break;}		//如果没有票务信息则需要特殊说明
		}
		if(if_ticket==0)
		{
			printf("\n\n\n------------------------------------------------\nYour ticket info is as follows !\n\n");
			while(i<=sum)
			{
				if(w[i]=='[')
				{
					if(w[i+1]=='1'){printf("buy ticket : ");}	//将文件中使用的1和0的标记翻译为实际的购票操作
					if(w[i+1]=='0'){printf("get refund for ticket : ");}
					i=i+3;
					int ss=i;
					while(w[i]!=']')
					{
						i++;
					}
					w[i]=L'\0';
					wprintf(&w[ss]);
					printf("\n\n");
				}
				i++;
			}
			printf("\n\n--------------------------------------------------\n");
		}
	}

	if(wherecome==1)	//打印出可以进行退票操作的票务信息，也即需要剔除那些购票后又退票了的票务信息
	{
		int i=0;
		int num=0;
		while(1)
		{
			i++;
			if(w[i]=='['){break;}
		}
		printf("\n\n\n------------------------------------------------\nThe ticket(s) below can be got refund of !\n\n");
		while(i<=sum-1)
		{
			if((w[i]=='[')&&(w[i+1]=='1'))	//对user的票务信息从上到下进行遍历，每读到一条购票信息时，在下面的票务信息中寻找是否有退票记录，如果有则该条购票记录不进行打印
			{
				int start=i+3;
				while(w[i]!=']'){i++;}
				w[i]=L'\0';
				wchar_t *cmp=&w[start];	//读出该行的购票信息（由“电影名  电影院名称  场次  座位”构成）
				int judge=0;
				int j=i;
				while(j<=sum-1)		//依次遍历之后的各行，寻找是否已经存在该条购票信息对应的退票信息
				{
					j++;		
					if((w[j]=='/')&&(w[j-1]=='0'))
					{
						int begin=j+1;
						j++;
						while((w[j]!=']')&&(j<=sum)){j++;}
						w[j]=L'\0';
						wchar_t *be_cmp=&w[begin];
						if(wcscmp(cmp,be_cmp)==0){judge=1;break;}	//如果找到了对应的退票信息（因为购退票信息均是格式化存储，所以只要字符串相同，前面的数字标记一个是1，一个是0，即可表明是对应的购退票信息）
					}
				}
				if(judge==0)	//如果judge==0说明没有找到对应的退票信息，则可以打印输出
				{
					wprintf(cmp);
					printf("\n\n");
				}
				w[j]=L']';		//改回来不然之后没法检索到']'字符
			}
			i++;		
		}
		printf("--------------------------------------------------\n");
	}
}