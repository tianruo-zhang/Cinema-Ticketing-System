#include "Header.h"

wchar_t *film_details()	//用户了解电影详细信息的函数
{
	initgraph(960,540,SHOWCONSOLE);
	loadimage(NULL,_T("pictures/homepage.png"));
	TCHAR title[] = _T("FILM DETAILS");setbkmode(TRANSPARENT);
	outtextxy(400, 120, title);
	int c=read_film_list(0);
	wchar_t *ch=(wchar_t*)malloc(sizeof(wchar_t));
	InputBox(ch,5,L"please enter the number of the film that you would like to know more about :",NULL,NULL,NULL,100,150);
	int n;
	n=_wtoi(ch);
	while((n>c+1)||(n<=0)||(p_film[n-1].if_on==0))		//检查输入，判断输入的数字是否在对应范围内以及该电影是否已经上架
	{
		memset(ch,0,5*sizeof(wchar_t));
		InputBox(ch,5,L"please enter the corresponding number of the film and make sure it is within range !",NULL,NULL,NULL,100,150);
		n=_wtoi(ch);
	}
	wchar_t *target=(wchar_t*)malloc(30*sizeof(wchar_t));
	target=p_film[n-1].name;
	return target;		//返回标记电影名的字符串
}