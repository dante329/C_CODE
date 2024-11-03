#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int buy_coca(int money)
//{
//	int bottle = money;
//	int sum = money;
//	while (bottle >= 2)
//	{
//		sum += bottle / 2;
//		bottle = bottle / 2 + bottle % 2;
//	}
//	
//	return sum;
//}
//
//int main()
//{
//	int money = 20;
//	int ret = buy_coca(money);
//	printf("%d",ret);
//	return 0;
//}
 
// 10_28 大小端存储
// 
// 在大端模式下，数据的最高字节（最重要的字节）存储在内存的低地址位置，而最低字节（最不重要的字节）存储在高地址位置
// 在小端模式下，数据的最低字节存储在内存的低地址位置，而最高字节存储在高地址位置。
// 高字节指的是一个多字节数字中数值较高的部分（即高位），而低字节则指的是数值较低的部分（即低位）
//int main()
//{
//	int i = 0x00000001;
//	if (*(char*)&i == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
//

// 11_03 数组指针 函数指针

//void print1(int(*p)[5], int r, int c)
//{
//	int i;
//	for (i = 0; i < r; i++)
//	{
//		int j;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", p[i][j]);
//			printf("%d ", *(*(p+i)+j) );
//		}
//		printf("\n");
//	}
//}

//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print1(arr,3,5);
//	//printf("%p\n", &arr);
//	//printf("%p\n", &arr+1);
//	//printf("%p\n", arr);
//	//printf("%p\n", arr+1);
//
//	return 0;
//}
//对于二维数组 数组名arr代表的意义是第一个一维数组的地址 即指向第一行数组 因为二维数组的首元素地址就是第一行数组
//arr+1跳过的是一行数组的大小（colum*int）
//&arr+1跳过的是整个二位数组的大小（colum*row*int）

//int main()
//{
//	int arr[10] = {0};
//	int(*p)[10] = arr;
//	printf("%p\n", arr+1);
//	printf("%p", p+1);
//	return 0;
//}


//问题1：这段代码的问题是什么？
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p1 = arr;
//	int (*p2)[5] = &arr;
//	printf("%d\n", p1[1]);
//	printf("%d", (*p2)[1]);
//	return 0;
//}
// 
//首先，p2[1] 等价于 *(p2 + 1)
//因为 p2 的类型是 int(*)[5]（指向一个包含 5 个 int 的数组），p2 + 1 会指向“下一个” int[5] 数组的位置
//p2[1] 实际上是 *(&arr + 1)，试图访问一个不存在的“下一组”5 个 int，因为 arr 只有一个包含 5 个 int 的数组。
//要想正确的使用就要先对p2解引用再访问下标1 即*(p2)[1] 相当于是*(*(&arr) + 1) 即 *(arr+1)
//*(&arr)对整个数组的地址解引用得到的就是这个数组 即数组名 即数组第一个元素的地址 就可以进行操作了 arr[1]或者(arr+1)都可以

//延伸问题2：int (*p2)[5] = &arr和int (*p2)[5] = arr这两种赋值方式有区别吗？
// 
//我已经规定了p2的类型是一个数组指针，所以这两种赋值并不会造成代码运行上的区别；
//使用& arr 和 arr 可以在语义上帮助理解代码，尤其是在类型的严格性和清晰性方面，
//选择哪种方式更多是关于代码的可读性和理解上的不同，而不会影响程序的行为。只要你明确理解它们的意义和语义，两者都可以正常使用。


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 2, b = 3;
//	//创建一个函数指针
//	int (*pf)(int, int) = &Add;
//	//int (*pf)(int, int) = Add;
//	//int (*pf)(int, int) = &Add与int (*pf)(int, int) = Add这两种写法的意义完全相同，只不过&更方便理解，实际上函数名就是它的地址
//
//	//使用函数指针调用Add函数
//	printf("%d\n", pf(2,3));
//	printf("%d\n",(*pf)(2, 3));
//	//这两种写法完全相同 只不过(*pf)(2, 3)更方便指针与解引用之间关系的理解
//	//注意不能写成*(pf)(2, 3)或者*pf(2, 3) 这样表示对函数结果解引用
//	 
//	//直接调用Add函数
//	printf("%d\n",Add(2, 3));
//	return 0;
//}