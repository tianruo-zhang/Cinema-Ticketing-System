#include "Header.h"

void print_user_history()	//打印用户的历史操作，包括注册、登录、按键情况等
{
	int num=0;
	char p[]="history.txt";	
	wchar_t *w=read_file(p);
	printf("\n\n\n------------------------------------------------\nThe following is the user history!\n\n");
	wprintf(w);
	printf("\n\n--------------------------------------------------\n");
}
