#include "Header.h"

void print_user_history()	//��ӡ�û�����ʷ����������ע�ᡢ��¼�����������
{
	int num=0;
	char p[]="history.txt";	
	wchar_t *w=read_file(p);
	printf("\n\n\n------------------------------------------------\nThe following is the user history!\n\n");
	wprintf(w);
	printf("\n\n--------------------------------------------------\n");
}
