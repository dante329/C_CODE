#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//typedef void (*)(int) pf_t;
//不能这样写typedef pf_t应该写在里面 跟函数指针变量申明的格式一样

//typedef void (*pf_t)(int);

//两段代码的理解
//int main()
//{
//	//第一个
//	(*(void (*)())0)();
//	//将0强制类型转换成一个void (*)()的函数指针 再对0解引用并调用0这个函数
//	//第二个
//	void (* signal(int, void (*)(int)) )(int);
//	//实际上是一个函数申明 signal函数类型为void (*)(int) 两个参数的类型为int，void (*)(int) 
//	//
//	//typedef过后可以将上面的式子转化为更简单的表达
//	//pf_t signal(int,ppf_t);
//
//	return 0;
//}


//11_04 函数指针，函数指针数组
//
//	实现加减乘除功能的计算器，并保留增加功能的空间

//函数申明与实现
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
////运行逻辑：使用函数指针数组，为将来增加功能留出空间
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int input = 0;
//	int ret = 0;
//	int (*pfarr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		//打印菜单
//		Menu();
//		//输入选项
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数->");
//			scanf("%d%d", &a, &b);
//			ret = pfarr[input](a, b);
//			printf("%d\n", ret);
//		}
//		/*scanf("%d%d", &a, &b);
//		ret = pfarr[input](a, b);
//		printf("%d\n", ret);*/
//		//这里是我逻辑上的漏洞，应该在input合法的前提下才读取数据进行运算，忘记了if条件过滤
//		else
//		{
//			printf("输入错误\n");
//		}
//	} while (input);
//	return 0;
//}

//数组指针 函数指针 函数指针数组 函数指针数组的指针
//真的很容易搞混
//
// *加特征法 变量名与*先结合是指针，与[]先结合是数组 最后跟的什么定语就是什么
// 
//数组指针 int (*parr)[5]
//函数指针 int (*pf)(int,int)
//函数指针数组 int (*pfarr[5])(int,int)		pfarr先与[]结合是数组
//函数指针数组的指针 int (*(*ppfarr)[5])(int,int)

//另解释 
//数组指针			int(*p)[5];					指向一个包含 5 个 int 元素的数组
//函数指针			int (*f)(int, int);			指向一个函数的指针，函数接收两个 int 参数并返回 int
//函数指针数组		int (*funcs[3])(int, int);	一个数组，包含 3 个函数指针
//函数指针数组的指针	int (*(*p)[3])(int, int);	一个指针，指向一个函数指针数组，该数组包含 3 个函数指针

//#include <stdio.h>

//冒泡排序
//
//void bubbleSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                // 交换 arr[j] 和 arr[j + 1]
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
//    printf("排序前的数组: ");
//    printArray(arr, n);
//
//    bubbleSort(arr, n);
//
//    printf("排序后的数组: ");
//    printArray(arr, n);
//
//    return 0;
//}


//冒泡排序改进（已经排序好了的情况就不执行程序）
//void bubbleSort(int arr[],int sz)
//{
//    int i = 0;
//    int flag = 1;//设立一个flag 看是否发生了元素的交换 如果交换了flag就会被改变
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
//                flag = 0;//如果进入了这个if交换了元素就flag=0
//            }
//        }
//        if (flag == 1)//在第一次循环结束后判断flag有没有被改变
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


//qsort函数（是一个标准库函数，需要导入stdlib.h）
//void qsort( void *base,
//			  size_t num, 
//			  size_t width,
//			  int (__cdecl *compare )(const void *elem1, const void *elem2 ) );

//#include <stdlib.h>

//cmp函数编写
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

