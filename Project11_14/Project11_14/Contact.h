#pragma once

#define MAX_DATA 100
#define MAX_NAME 20
#define MAX_GEN 5
#define MAX_TELE 11
#define MAX_ADDR 20

#include <stdio.h>
#include <string.h>
#include <assert.h>

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
typedef struct Contact
{
	struct PeoInfo data[MAX_DATA];
	int count;
} Contact;

//函数声明
void Contact_Add(Contact*);

void Contact_Print(Contact*);

void InitContact(Contact*);