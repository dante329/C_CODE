#pragma once

#define MAX_DATA 100
#define MAX_NAME 20
#define MAX_GEN 5
#define MAX_TELE 11
#define MAX_ADDR 20
#define DEFUALT_SZ 3
#define INC_SZ 3

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

//定义一个枚举菜单
enum Option
{
	Exit,
	Add,
	Del,
	Modify,
	Print,
	Sort,
	Search
};

//定义结构体
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GEN];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInfo;

//因为要统计通讯录中的用户数量，将数量和PeoInfo封装在一起，做一个新的struct Contact
/*
typedef struct Contact
{
	struct PeoInfo data[MAX_DATA];
	int count;
} Contact;
*/

//动态内存版
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
} Contact;

//函数声明
void Destory_Mem(Contact*);

void InitContact(Contact*);

void Contact_Add(Contact*);

void Contact_Print(Contact*);

void Contact_Del(Contact*);

void Contact_Search(Contact*);

void Contact_Modify(Contact*);

void Contact_Sort(Contact*);

void SaveContact(Contact*);
