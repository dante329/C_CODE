#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//实现通讯录，菜单，添加，查询，修改，排序，打印，退出


void menu()
{
	printf("************************************\n");
	printf("*******1.Add********2.Del***********\n");
	printf("*******3.Modify*****4.Print*********\n");
	printf("*******5.Sort*******6.Search********\n");
	printf("*******0.Exit***********************\n");
	printf("************************************\n");
}

int main()
{	 	
	int input;	
	Contact con; //先创建一个通讯录变量，下面的add等操作要对这个变量进行更改
	//对con初始化，写一个函数，模块化实现功能
	InitContact(&con);
	do
	{
		menu();
		printf("请输入你要操作的选项：");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Contact_Add(&con);
			break;
		case Del:
			Contact_Del(&con);
			break;
		case Modify:
			Contact_Modify(&con);
			break;
		case Print:
			Contact_Print(&con);
			break;
		case Sort:
			Contact_Sort(&con);
			break;
		case Search:
			Contact_Search(&con);
			break;
		case Exit:
			Destory_Mem(&con);
			printf("已退出程序\n");
			break;
		default:
			printf("输入错误");
		}

	} while (input);
	return 0;
}