#include "Header.h"

int click_button(int x,int y,int x_width,int y_width)	//�ж��Ƿ����˶�Ӧ��ť�ĺ�������Ҫ����ȷ�ϰ�����
{
	ExMessage m;
	int iden=0;
	while(iden!=1)
	{
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN)
		{
			if((m.x>(x-5) && m.x<(x+x_width+5)) && (m.y>(y-5) && m.y<(y+y_width+5))){iden=1;break;}
		}
	}
	return iden;
}