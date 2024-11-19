#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
//静态内存版本
//static int FindbyName(Contact* pc)
//{
//	int i = 0;
//	char name[MAX_DATA] = { 0 };
//	scanf("%s", name);
//	for (i = 0; i < pc->count; i++)
//	{
//		if (strcmp(pc->data[i].name, name) == 0)
//			return i;
//	}
//}

//动态内存版本
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

void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		//c语言if内定义的变量ptr出了这个if就没办法访问了
		//if 语句内定义的变量的作用域只限于该 if 块，块外无法访问。这是因为 C 语言的作用域是基于代码块（大括号 {}）的。变量在声明时，其作用域仅限于包含它的大括号内。
		if (ptr == NULL)
		{
			printf("Contact_Add::%s", strerror(errno));
		}
		else
		{
			pc->data = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
			pc->capacity += INC_SZ;
		}
	}
	printf("增容成功\n");
}

void LoadContact(Contact* pc)
{
	assert(pc);
	if (pc == 0)
	{
		perror("LoadContact");
		return;
	}
	FILE* pf = fopen("Contact.txt", "rb");
	//PeoInfo* ptr = malloc(sizeof(PeoInfo*));
	PeoInfo ptr = { 0 };
	while (fread(&ptr, sizeof(PeoInfo), 1, pf) == 1)
	{
		CheckCapacity(pc);
		pc->data[pc->count] = ptr;
		pc->count++;	
	}
	fclose(pf);
	pf = NULL;

	//容量3
}

//静态内存版本
//void InitContact(Contact* pc)
//{
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态内存版本
void InitContact(Contact* pc)
{
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFUALT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
	}
	pc->capacity = DEFUALT_SZ;
	LoadContact(pc);
}

//静态内存版本
//void Contact_Add(Contact * pc)
//{
//	assert(pc);
//	if (pc->count == MAX_DATA)
//	{
//		printf("通讯录已满！");
//		return;
//	}
//
//	printf("请输入姓名：");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入年龄：");
//	scanf("%d", &pc->data[pc->count].age);
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->count].gender);
//	printf("请输入手机号：");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->count].addr);
//
//	pc->count++;
//	printf("增加成功\n");
//}

//动态内存版本
void Contact_Add(Contact* pc)
{
	assert(pc);
	/*if (pc->count == pc->capacity)
	{
		pc->data = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ)*sizeof(PeoInfo));
	}*///这样写是对的吗？很明显不对，realloc之后没有任何判断直接赋值给pc->data这是一种很危险的行为，如果赋值失败realloc会返回一个NULL，会将pc->data覆盖
	//if (pc->count == pc->capacity)
	//{
	//	PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
	//	//c语言if内定义的变量ptr出了这个if就没办法访问了
	//	//if 语句内定义的变量的作用域只限于该 if 块，块外无法访问。这是因为 C 语言的作用域是基于代码块（大括号 {}）的。变量在声明时，其作用域仅限于包含它的大括号内。
	//	if (ptr == NULL)
	//	{
	//		printf("Contact_Add::%s", strerror(errno));
	//	}
	//	else
	//	{
	//		pc->data = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
	//		pc->capacity += INC_SZ;
	//	}
	//}
	//这个增容功能在别的函数中可能还会使用，就将它包装成一个函数，模块化功能的思想
	CheckCapacity(pc);
	
	
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

void Destory_Mem(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//退出程序前执行保存通讯录
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("Contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(&(pc->data[i]), sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}