#pragma once

#define MAX_DATA 100
#define MAX_NAME 20
#define MAX_GEN 5
#define MAX_TELE 11
#define MAX_ADDR 20

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//����ṹ��
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GEN];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInfo;

//��ΪҪͳ��ͨѶ¼�е��û���������������PeoInfo��װ��һ����һ���µ�struct Contact
typedef struct Contact
{
	struct PeoInfo data[MAX_DATA];
	int count;
} Contact;

//��������

void InitContact(Contact*);

void Contact_Add(Contact*);

void Contact_Print(Contact*);

void Contact_Del(Contact*);

void Contact_Search(Contact*);

void Contact_Modify(Contact*);

void Contact_Sort(Contact*);
