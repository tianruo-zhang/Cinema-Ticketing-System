#include "Header.h"

void print_ticket_info(int wherecome)	//��ӡ�û���Ʊ����Ϣ������wherecome���ڱ�ǵ���λ�ã�wherecome==0��ֱ�Ӵ�ӡuser�ı��д洢��Ʊ����Ϣ��wherecome==1�ǵ�user��Ҫ������Ʊ����ʱ��ӡ�����Խ�����Ʊ������Ʊ����Ϣ
{
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int sum=wcslen(w);
	int if_ticket=0;
	if(wherecome==0)	//�����Ǵ�ӡƱ����Ϣ
	{
		int i=0;
		while(1)
		{
			i++;
			if(w[i]==L'['){break;}
			if(w[i+1]=='\0'){printf("no ticket info !\n\n");if_ticket=1;break;}		//���û��Ʊ����Ϣ����Ҫ����˵��
		}
		if(if_ticket==0)
		{
			printf("\n\n\n------------------------------------------------\nYour ticket info is as follows !\n\n");
			while(i<=sum)
			{
				if(w[i]=='[')
				{
					if(w[i+1]=='1'){printf("buy ticket : ");}	//���ļ���ʹ�õ�1��0�ı�Ƿ���Ϊʵ�ʵĹ�Ʊ����
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

	if(wherecome==1)	//��ӡ�����Խ�����Ʊ������Ʊ����Ϣ��Ҳ����Ҫ�޳���Щ��Ʊ������Ʊ�˵�Ʊ����Ϣ
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
			if((w[i]=='[')&&(w[i+1]=='1'))	//��user��Ʊ����Ϣ���ϵ��½��б�����ÿ����һ����Ʊ��Ϣʱ���������Ʊ����Ϣ��Ѱ���Ƿ�����Ʊ��¼��������������Ʊ��¼�����д�ӡ
			{
				int start=i+3;
				while(w[i]!=']'){i++;}
				w[i]=L'\0';
				wchar_t *cmp=&w[start];	//�������еĹ�Ʊ��Ϣ���ɡ���Ӱ��  ��ӰԺ����  ����  ��λ�����ɣ�
				int judge=0;
				int j=i;
				while(j<=sum-1)		//���α���֮��ĸ��У�Ѱ���Ƿ��Ѿ����ڸ�����Ʊ��Ϣ��Ӧ����Ʊ��Ϣ
				{
					j++;		
					if((w[j]=='/')&&(w[j-1]=='0'))
					{
						int begin=j+1;
						j++;
						while((w[j]!=']')&&(j<=sum)){j++;}
						w[j]=L'\0';
						wchar_t *be_cmp=&w[begin];
						if(wcscmp(cmp,be_cmp)==0){judge=1;break;}	//����ҵ��˶�Ӧ����Ʊ��Ϣ����Ϊ����Ʊ��Ϣ���Ǹ�ʽ���洢������ֻҪ�ַ�����ͬ��ǰ������ֱ��һ����1��һ����0�����ɱ����Ƕ�Ӧ�Ĺ���Ʊ��Ϣ��
					}
				}
				if(judge==0)	//���judge==0˵��û���ҵ���Ӧ����Ʊ��Ϣ������Դ�ӡ���
				{
					wprintf(cmp);
					printf("\n\n");
				}
				w[j]=L']';		//�Ļ�����Ȼ֮��û��������']'�ַ�
			}
			i++;		
		}
		printf("--------------------------------------------------\n");
	}
}