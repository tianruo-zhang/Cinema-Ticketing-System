#include "Header.h"

wchar_t *edit_details(wchar_t *point,int catt,wchar_t *newinfo)	//用于修改电影各项的信息
{
	if((catt>=0)&&(catt<=9))	//当修改的是该部电影的基本信息时，catt标记的需要修改的信息所在的行数-1
	{
		char bb[100]="film";
		char *p=cat(point,bb);
		int num=0;
		int i=0;
		int b=0;
		int k=0;
		wchar_t *w=read_file(p);
		num=wcslen(w);

		FILE  *fp1;	//将该信息前的行重新写入该文本中
		if((fp1=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}
		while(b<catt)
		{
			if(w[i]=='\n'){b++;}
			wchar_t c;
			c=w[i];
			fwprintf(fp1,&c);
			i++;
		}
		fwprintf(fp1,newinfo);	//该信息对应的行用newinfo替换

		wchar_t *oldinfo=(wchar_t*)malloc(sizeof(wchar_t));	 //读取原本该行的信息，用oldinfo存储，方便之后信息更改情况的显示
		while(b==catt)
		{
			if(w[i]!='\n'){oldinfo[k]=w[i];}
			if(w[i]=='\n'){oldinfo[k]=L'\0';b++;}
			k++;
			i++;
			oldinfo=(wchar_t*)realloc(oldinfo,(k+1)*sizeof(wchar_t*));
		}
		fwprintf(fp1,L"\n");
		fwprintf(fp1,&w[i]);	//该行后的信息全部写入该文本中
		fclose(fp1);

		if(catt==0)	//实现文件名称的同步更改，通过将信息复制到新的文件名文件中、删除旧的文件名文件来实现
		{
			char mm[100]="film";
			char *new_file_name=cat(newinfo,mm);			
			char mmm[100]="film";
			char *old_file_name=cat(oldinfo,mmm);		
			wchar_t *ans=read_file(old_file_name);		
			FILE *f;
			f=fopen(new_file_name,"w");
			if(f==NULL){printf("不能打开%s文件！\n",new_file_name);exit(1);}	//打不开文件则报错
			fwprintf(f,ans);
			int d=remove(old_file_name);
			fclose(f);
		}

		if((catt==0)||(catt==9)||(catt==10))	//film list.txt中有相关信息的也需要进行更改
		{
			int number=0,gang_n=0;		//gang_n存储的是‘/’的个数
			wchar_t *fl=read_file("film list.txt");
			number=wcslen(fl);
			int judgee=0;
			int kk=0,tt=0;
			for(kk=0;kk<=number-wcslen(oldinfo);kk++)
			{
				wchar_t cc;
				if(fl[kk]=='/'){gang_n++;}
				if(((gang_n%4==0)&&(catt==0))||((gang_n%4==1)&&(catt==9))||((gang_n==2)&&(catt==10)))
				{
					for(tt=0;tt<wcslen(oldinfo);tt++)
					{
						if(fl[kk+tt]!=oldinfo[tt]){break;}
					}
					if((tt>=wcslen(oldinfo))&&(fl[kk+tt]==L'/')){break;}		
				}
			}
			wchar_t *temp=&fl[kk+wcslen(oldinfo)];
			FILE *fp2=fopen("film list.txt","w");	
			for(int a=0;a<kk;a++)
			{
				wchar_t cc;
				cc=fl[a];
				fwprintf(fp2,&cc);	
			}
			fwprintf(fp2,newinfo);
			int j=0;
			fwprintf(fp2,temp);
			fclose(fp2);
		}
		return oldinfo;	//传回oldinfo便于信息更改情况的显示
	}

	if(catt==10)	//更改是否上架的信息，调用film_if_on函数来实现
	{
		film_if_on(point,newinfo);
		return point;
	}

	if(catt==11)	//更改票量，调用set_ticket函数来实现
	{
		set_ticket(point);
		return point;
	}

	if(catt==12)	//删除电影，调用delete_film函数来实现
	{
		int del=delete_film(point);
		return point;
	}
}