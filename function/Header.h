#ifndef HEADER_H
#define HEADER_H

//һЩͷ�ļ�
#include <stdio.h>	
#include <graphics.h>
#include <wchar.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

//һЩ�������ܺ���
char *cat(wchar_t *file,char package[100]);		//�ļ���������
wchar_t *read_file(char *p);	//�ļ��Ķ�д
int choose_button(int x11,int x12,int y11,int y12,int x21,int x22,int y21,int y22);		//ѡ����
int click_button(int x,int y,int x_width,int y_width);		//�ж��Ƿ����ĺ���

//��ģ�麯��
int login();		//launch screenѡ����ݺ���
void administer_login();	//administer��¼���溯��
int user_login();		//userѡ���Ƿ����˺ŵĺ���
void user_straightly_login();	//user�����˺ź�ĵ�¼���溯��
wchar_t *new_user(int choose);	//ע�����û�
int home_page(int n);	//homepage���غ���
int me_page();	//user����ҳ��
void user_change_id();		//user����id
void user_change_pswd();	//user����password
void vip();		//vipҳ��
int user_info_page();	//administer�鿴user info
void print_user_list();		//��ӡuser list
void add_history(wchar_t*point);		//uesr����ȫ��д��history.txt�ļ���
void print_user_history();		//��ӡuser�Ĳ�����ʷ
int user_film_page();		//user�����film page
void print_film_list();	//��ӡfilm list
int read_film_list(int judge);		//��ȡfilm list���ݲ�����film�ṹ��,���Ҹ��������n�ֱ���а�ratings����Ͱ�names����
int read_film_detailed_info(wchar_t *pointer);		//��ȡ��Ӧ��Ӱ��txt�ļ��е���Ϣ
wchar_t *film_details();	//ʹ�ñ�Ų�ѯĳ����Ӱ����ϸ��Ϣ
void edit_film_info(int n);		//administer���/������ص�Ӱ��Ϣ
wchar_t *edit_details(wchar_t *point,int catt,wchar_t *newinfo);	//administer�Ե�Ӱ�����Ϣ
wchar_t *add_new_film();	//������Ӱ
int delete_film(wchar_t *name);	//ɾ����Ӱ
void film_if_on(wchar_t *name,wchar_t *newinfo);	//�޸ĵ�Ӱ�Ƿ��ϼ�
int *search_with_cat(int wherecome,wchar_t *name,int not_print);	//ʹ�����ͽ��м���
int *search_with_roles(int wherecome,wchar_t *name,int not_print);	//ʹ�����ݽ��м���
void add_to_favorites(wchar_t *name);	//��ӵ��ղؼ�
void set_ticket(wchar_t *point);	//����Ʊ��
void print_seat(wchar_t *point,int numm);	//����ѡ����λ�ĺ���
void ticket_page(wchar_t *pointer,int wherecome);	//���ڹ�Ʊ�ĺ���
void edit_seat(wchar_t *name,wchar_t *cinema,wchar_t *session,wchar_t *seat);	//���ĵ�Ӱtxt�ļ��е���λ��Ϣ
void print_ticket_info(int wherecome);	//��ӡticket��Ϣ
int user_ticket_info_page();	//ticket infoҳ��
void ticket_refund();	//user��Ʊ����
int check_if_favorites(wchar_t *name);	//����Ƿ��Ѽ���favorites
void print_favorites();	//��ӡ��FAVORITES
void recommend();	//�Ƽ�user���ܸ���Ȥ�ĵ�Ӱ�ĺ���

//ȫ�ֱ���
extern wchar_t *p_user;	//��¼user��id
void add_history(wchar_t*pointer);	//����history�����ļ�¼
extern float acc;	//�ۿ�
extern wchar_t *film_name;	//��Ӱ���Ƶļ�¼
extern struct film	//��Ӱ��Ϣ��¼�Ľṹ��
{
	int bianhao;
	wchar_t name[50];
	float ratings;
	int if_on;
};
extern struct film *p_film;	//ָ��ýṹ���ָ��

#endif HEADER_H