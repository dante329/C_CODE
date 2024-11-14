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
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空，无法删除\n");
	}
	printf("请输入你要删除的用户名：");
	//char name[MAX_DATA] = { 0 };
	//scanf("%s", name);
	int n = FindbyName(pc);
	for (; n < pc->count; n++)
	{
		pc->data[n] = pc->data[n + 1];
	}
	pc->count--;//删除一个data中的元素之后，相当于少了一个数据，count就要-1变成了99，这样data[100]也无法被访问到了，一举两得
	printf("删除成功\n");
}

void Contact_Search(const Contact* pc)
{
	assert(pc);
	printf("请输入要查找的用户名：");
	int i = FindbyName(pc);
	if (i == 0)
	{
		printf("找到了\n");
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
	printf("请输入要修改的用户名：");
	int i = FindbyName(pc);
	if (i == 0)
	{
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
	}
	printf("修改成功\n");
}

int compare_byName(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void Contact_Sort(Contact* pc)
{
	assert(pc);
	qsort(pc->data,pc->count,sizeof(PeoInfo),compare_byName);
	printf("排序成功\n");
}