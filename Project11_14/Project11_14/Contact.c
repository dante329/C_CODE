#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

int Search

void Contact_Add(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX_DATA)
	{
		printf("ͨѶ¼������");
		return;
	}

	printf("������������");
	scanf("%s", pc->data[pc->count].name);
	printf("���������䣺");
	scanf("%d", &pc->data[pc->count].age);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->count].gender);
	printf("�������ֻ��ţ�");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
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
	printf("��������Ҫɾ�����û�����");
	char name[MAX_DATA] = { 0 };
	scanf("%s", name);
	int i = 0;
	Search(pc);
	
}