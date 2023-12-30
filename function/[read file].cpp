#include "Header.h"

wchar_t *read_file(char *p)	//读取p对应的文件中的字符并存入w数组，方便后续对字符串进行更改的操作
{
	int ch;
	int num=0;
	wchar_t *w=(wchar_t*)malloc(sizeof(wchar_t));
	FILE  *fp;
	if((fp=fopen(p,"r"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}		//打不开文件的报错
	ch=fgetc(fp);	
	while (ch!=EOF)
	{
		w[num]=ch;	
		num++;
		w=(wchar_t*)realloc(w,(num+1)*sizeof(wchar_t));
		ch=fgetc(fp);
	}
	fclose(fp);
	w[num]=L'\0';
	return w;
}