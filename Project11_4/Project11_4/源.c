#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//typedef void (*)(int) pf_t;
//��������дtypedef pf_tӦ��д������ ������ָ����������ĸ�ʽһ��

//typedef void (*pf_t)(int);

//���δ�������
//int main()
//{
//	//��һ��
//	(*(void (*)())0)();
//	//��0ǿ������ת����һ��void (*)()�ĺ���ָ�� �ٶ�0�����ò�����0�������
//	//�ڶ���
//	void (* signal(int, void (*)(int)) )(int);
//	//ʵ������һ���������� signal��������Ϊvoid (*)(int) ��������������Ϊint��void (*)(int) 
//	//
//	//typedef������Խ������ʽ��ת��Ϊ���򵥵ı��
//	//pf_t signal(int,ppf_t);
//
//	return 0;
//}


//11_04 ����ָ�룬����ָ������
//
//	ʵ�ּӼ��˳����ܵļ����������������ӹ��ܵĿռ�

//����������ʵ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Menu()
//{
//	printf("******************************\n");
//	printf("********1.Add****2.Sub********\n");
//	printf("********3.Mul****4.Div********\n");
//	printf("************0.exit************\n");
//	printf("******************************\n");
//}
////�����߼���ʹ�ú���ָ�����飬Ϊ�������ӹ��������ռ�
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int input = 0;
//	int ret = 0;
//	int (*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		//��ӡ�˵�
//		Menu();
//		//����ѡ��
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("�˳�����\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("����������������->");
//			scanf("%d%d", &a, &b);
//			ret = pfarr[input](a, b);
//			printf("%d\n", ret);
//		}
//		/*scanf("%d%d", &a, &b);
//		ret = pfarr[input](a, b);
//		printf("%d\n", ret);*/
//		//���������߼��ϵ�©����Ӧ����input�Ϸ���ǰ���²Ŷ�ȡ���ݽ������㣬������if��������
//		else
//		{
//			printf("�������\n");
//		}
//	} while (input);
//	return 0;
//}

//����ָ�� ����ָ�� ����ָ������ ����ָ�������ָ��
//��ĺ����׸��
//
// *�������� ��������*�Ƚ����ָ�룬��[]�Ƚ�������� ������ʲô�������ʲô
// 
//����ָ�� int (*parr)[5]
//����ָ�� int (*pf)(int,int)
//����ָ������ int (*pfarr[5])(int,int)		pfarr����[]���������
//����ָ�������ָ�� int (*(*ppfarr)[5])(int,int)

//����� 
//����ָ��			int(*p)[5];					ָ��һ������ 5 �� int Ԫ�ص�����
//����ָ��			int (*f)(int, int);			ָ��һ��������ָ�룬������������ int ���������� int
//����ָ������		int (*funcs[3])(int, int);	һ�����飬���� 3 ������ָ��
//����ָ�������ָ��	int (*(*p)[3])(int, int);	һ��ָ�룬ָ��һ������ָ�����飬��������� 3 ������ָ��

//#include <stdio.h>

//ð������
//
//void bubbleSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                // ���� arr[j] �� arr[j + 1]
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void printArray(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int arr[] = { 64, 34, 25, 12, 22, 11, 90 ,2};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("����ǰ������: ");
//    printArray(arr, n);
//
//    bubbleSort(arr, n);
//
//    printf("����������: ");
//    printArray(arr, n);
//
//    return 0;
//}


//ð������Ľ����Ѿ�������˵�����Ͳ�ִ�г���
//void bubbleSort(int arr[],int sz)
//{
//    int i = 0;
//    int flag = 1;//����һ��flag ���Ƿ�����Ԫ�صĽ��� ���������flag�ͻᱻ�ı�
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        
//        for (j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//                flag = 0;//������������if������Ԫ�ؾ�flag=0
//            }
//        }
//        if (flag == 1)//�ڵ�һ��ѭ���������ж�flag��û�б��ı�
//        {
//            break;
//        }
//    }
//}
//
//int main()
//{
//    int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubbleSort(arr,sz);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}


//qsort��������һ����׼�⺯������Ҫ����stdlib.h��
//void qsort( void *base,
//			  size_t num, 
//			  size_t width,
//			  int (__cdecl *compare )(const void *elem1, const void *elem2 ) );

//#include <stdlib.h>

//cmp������д
//int cmp_int(const void* e1,const void* e2)
//{
//	return (*(int*)e1) - (*(int*)e2);
//}
//
//void printArray(int arr[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr,sz,sizeof(arr[0]),cmp_int);
//	printArray(arr, sz);
//	return 0;
//}

