#include "Header.h"

int check_if_favorites(wchar_t *name)	//判断是否已经收藏该电影的函数，从而判断是显示like按钮还是显示已收藏的文字
{
	int flag=0;	//标记是否在收藏夹中
	int hang=0;	//行数
	char b[100]="user";
	char *p=cat(p_user,b);
	wchar_t *w=read_file(p);
	int bkwd=0;	//回车键计数
	int i=0;
	while(bkwd<2)
	{
		i++;	
		if(w[i]=='\n'){bkwd++;}
	}
	i++;
	wchar_t *temp=(wchar_t*)malloc((wcslen(name)+1)*sizeof(wchar_t));
	while(bkwd==2)	//读取该用户的文本文件中的第三行是否存在这个电影名的字符串，从而判断是否收藏
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