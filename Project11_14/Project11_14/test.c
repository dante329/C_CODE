#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//ʵ��ͨѶ¼���˵�����ӣ���ѯ���޸ģ����򣬴�ӡ���˳�





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
	Contact con; //�ȴ���һ��ͨѶ¼�����������add�Ȳ���Ҫ������������и���
	//��con��ʼ����дһ��������ģ�黯ʵ�ֹ���
	InitContact(&con);
	do
	{
		menu();
		printf("��������Ҫ������ѡ�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Contact_Add(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			Contact_Print(&con);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			break;
		default:
			printf("�������");
		}

	} while (input);
	return 0;
}