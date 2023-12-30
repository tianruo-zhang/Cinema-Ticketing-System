#ifndef HEADER_H
#define HEADER_H

//一些头文件
#include <stdio.h>	
#include <graphics.h>
#include <wchar.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

//一些基础功能函数
char *cat(wchar_t *file,char package[100]);		//文件名的连接
wchar_t *read_file(char *p);	//文件的读写
int choose_button(int x11,int x12,int y11,int y12,int x21,int x22,int y21,int y22);		//选择函数
int click_button(int x,int y,int x_width,int y_width);		//判断是否点击的函数

//各模块函数
int login();		//launch screen选择身份函数
void administer_login();	//administer登录界面函数
int user_login();		//user选择是否有账号的函数
void user_straightly_login();	//user已有账号后的登录界面函数
wchar_t *new_user(int choose);	//注册新用户
int home_page(int n);	//homepage加载函数
int me_page();	//user个人页面
void user_change_id();		//user更改id
void user_change_pswd();	//user更改password
void vip();		//vip页面
int user_info_page();	//administer查看user info
void print_user_list();		//打印user list
void add_history(wchar_t*point);		//uesr操作全部写入history.txt文件中
void print_user_history();		//打印user的操作历史
int user_film_page();		//user浏览的film page
void print_film_list();	//打印film list
int read_film_list(int judge);		//读取film list内容并存入film结构体,并且根据输入的n分别进行按ratings排序和按names排序
int read_film_detailed_info(wchar_t *pointer);		//读取对应电影的txt文件中的信息
wchar_t *film_details();	//使用编号查询某部电影的详细信息
void edit_film_info(int n);		//administer添加/更改相关电影信息
wchar_t *edit_details(wchar_t *point,int catt,wchar_t *newinfo);	//administer对电影相关信息
wchar_t *add_new_film();	//新增电影
int delete_film(wchar_t *name);	//删除电影
void film_if_on(wchar_t *name,wchar_t *newinfo);	//修改电影是否上架
int *search_with_cat(int wherecome,wchar_t *name,int not_print);	//使用类型进行检索
int *search_with_roles(int wherecome,wchar_t *name,int not_print);	//使用主演进行检索
void add_to_favorites(wchar_t *name);	//添加到收藏夹
void set_ticket(wchar_t *point);	//设置票量
void print_seat(wchar_t *point,int numm);	//用于选择座位的函数
void ticket_page(wchar_t *pointer,int wherecome);	//用于购票的函数
void edit_seat(wchar_t *name,wchar_t *cinema,wchar_t *session,wchar_t *seat);	//更改电影txt文件中的座位信息
void print_ticket_info(int wherecome);	//打印ticket信息
int user_ticket_info_page();	//ticket info页面
void ticket_refund();	//user退票函数
int check_if_favorites(wchar_t *name);	//检查是否已加入favorites
void print_favorites();	//打印出FAVORITES
void recommend();	//推荐user可能感兴趣的电影的函数

//全局变量
extern wchar_t *p_user;	//记录user的id
void add_history(wchar_t*pointer);	//用于history操作的记录
extern float acc;	//折扣
extern wchar_t *film_name;	//电影名称的记录
extern struct film	//电影信息记录的结构体
{
	int bianhao;
	wchar_t name[50];
	float ratings;
	int if_on;
};
extern struct film *p_film;	//指向该结构体的指针

#endif HEADER_H