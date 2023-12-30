#include "Header.h"

int choose_button(int x11,int x12,int y11,int y12,int x21,int x22,int y21,int y22)	//判断点击了哪个选项的按钮
{
	ExMessage m;
	int iden;
	while(1)
	{
		m = getmessage(EM_MOUSE);
		if (m.message==WM_LBUTTONDOWN) 
		{
			if((m.x>x11 && m.x<x12) && (m.y>y11 && m.y<y12)){iden=1;break;}
			if((m.x>x21 && m.x<x22) && (m.y>y21 && m.y<y22)){iden=2;break;}
		}
	}
	return iden;
}