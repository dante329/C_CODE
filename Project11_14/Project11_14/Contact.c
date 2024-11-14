#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

static int FindbyName(Contact* pc)
{
	int i = 0;
	char name[MAX_DATA] = { 0 };
	scanf("%s", name);
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
}

void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void Contact_Add(Contact * pc)
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
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].gender,
			pc->data[i].tele,
			pc->data[i].addr);
	}	
}

void Contact_Del(Contact* pc)
{
	assert(pc);
	if (pc -> count == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
	}
	printf("��������Ҫɾ�����û�����");
	//char name[MAX_DATA] = { 0 };
	//scanf("%s", name);
	int n = FindbyName(pc);
	for (; n < pc->count; n++)
	{
		pc->data[n] = pc->data[n + 1];
	}
	pc->count--;//ɾ��һ��data�е�Ԫ��֮���൱������һ�����ݣ�count��Ҫ-1�����99������data[100]Ҳ�޷������ʵ��ˣ�һ������
	printf("ɾ���ɹ�\n");
}

void Contact_Search(const Contact* pc)
{
	assert(pc);
	printf("������Ҫ���ҵ��û�����");
	int i = FindbyName(pc);
	if (i == 0)
	{
		printf("�ҵ���\n");
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-20s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].gender,
			pc->data[i].tele,
			pc->data[i].addr);
	}
	
}

void Contact_Modify(Contact* pc)
{
	assert(pc);
	printf("������Ҫ�޸ĵ��û�����");
	int i = FindbyName(pc);
	if (i == 0)
	{
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
	}
	printf("�޸ĳɹ�\n");
}

int compare_byName(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void Contact_Sort(Contact* pc)
{
	assert(pc);
	qsort(pc->data,pc->count,sizeof(PeoInfo),compare_byName);
	printf("����ɹ�\n");
}