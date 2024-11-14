#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

int Search

void Contact_Add(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX_DATA)
	{
		printf("通讯录已满！");
		return;
	}

	printf("请输入姓名：");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->count].gender);
	printf("请输入手机号：");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功\n");
}

void Contact_Print(const Contact* pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].gender,
			pc->data[i].tele,
			pc->data[i].addr);
	}
	
	
}

void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data,0,sizeof(pc->data));
}

void Contact_Del(Contact* pc)
{
	assert(pc);
	printf("请输入你要删除的用户名：");
	char name[MAX_DATA] = { 0 };
	scanf("%s", name);
	int i = 0;
	Search(pc);
	
}