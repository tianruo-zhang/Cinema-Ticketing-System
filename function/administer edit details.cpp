#include "Header.h"

wchar_t *edit_details(wchar_t *point,int catt,wchar_t *newinfo)	//�����޸ĵ�Ӱ�������Ϣ
{
	if((catt>=0)&&(catt<=9))	//���޸ĵ��Ǹò���Ӱ�Ļ�����Ϣʱ��catt��ǵ���Ҫ�޸ĵ���Ϣ���ڵ�����-1
	{
		char bb[100]="film";
		char *p=cat(point,bb);
		int num=0;
		int i=0;
		int b=0;
		int k=0;
		wchar_t *w=read_file(p);
		num=wcslen(w);

		FILE  *fp1;	//������Ϣǰ��������д����ı���
		if((fp1=fopen(p,"w"))==NULL){printf("\n The file: %s  can not  be  opened \n",p);exit(1);}
		while(b<catt)
		{
			if(w[i]=='\n'){b++;}
			wchar_t c;
			c=w[i];
			fwprintf(fp1,&c);
			i++;
		}
		fwprintf(fp1,newinfo);	//����Ϣ��Ӧ������newinfo�滻

		wchar_t *oldinfo=(wchar_t*)malloc(sizeof(wchar_t));	 //��ȡԭ�����е���Ϣ����oldinfo�洢������֮����Ϣ�����������ʾ
		while(b==catt)
		{
			if(w[i]!='\n'){oldinfo[k]=w[i];}
			if(w[i]=='\n'){oldinfo[k]=L'\0';b++;}
			k++;
			i++;
			oldinfo=(wchar_t*)realloc(oldinfo,(k+1)*sizeof(wchar_t*));
		}
		fwprintf(fp1,L"\n");
		fwprintf(fp1,&w[i]);	//���к����Ϣȫ��д����ı���
		fclose(fp1);

		if(catt==0)	//ʵ���ļ����Ƶ�ͬ�����ģ�ͨ������Ϣ���Ƶ��µ��ļ����ļ��С�ɾ���ɵ��ļ����ļ���ʵ��
		{
			char mm[100]="film";
			char *new_file_name=cat(newinfo,mm);			
			char mmm[100]="film";
			char *old_file_name=cat(oldinfo,mmm);		
			wchar_t *ans=read_file(old_file_name);		
			FILE *f;
			f=fopen(new_file_name,"w");
			if(f==NULL){printf("���ܴ�%s�ļ���\n",new_file_name);exit(1);}	//�򲻿��ļ��򱨴�
			fwprintf(f,ans);
			int d=remove(old_file_name);
			fclose(f);
		}

		if((catt==0)||(catt==9)||(catt==10))	//film list.txt���������Ϣ��Ҳ��Ҫ���и���
		{
			int number=0,gang_n=0;		//gang_n�洢���ǡ�/���ĸ���
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
		return oldinfo;	//����oldinfo������Ϣ�����������ʾ
	}

	if(catt==10)	//�����Ƿ��ϼܵ���Ϣ������film_if_on������ʵ��
	{
		film_if_on(point,newinfo);
		return point;
	}

	if(catt==11)	//����Ʊ��������set_ticket������ʵ��
	{
		set_ticket(point);
		return point;
	}

	if(catt==12)	//ɾ����Ӱ������delete_film������ʵ��
	{
		int del=delete_film(point);
		return point;
	}
}