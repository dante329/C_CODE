#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
int main()
{
	unsigned char a = 200;
	//200的二进制序列是00000000000000000000000011001000
	//但是要存入a中，一个大内存的数字存入一个小内存的变量中，就会发生截断，只存入11001000
	unsigned char b = 100;
	//存入01100100
	unsigned char c = 0;

	c = a + b;
	//如果操作数的类型比 int 更小（例如 char 或 short），那么它们会被提升到 int 类型（或 unsigned int，如果 int 不足以容纳这些值）
	//在执行 a + b 时，a 和 b 会先被提升为 int 类型，然后再进行相加操作。
	//00000000000000000000000011001000 -a
	//00000000000000000000000001100100 -b
	//00000000000000000000000100101100 a+b
	//存入c时会发生截断 00101100 -c
	printf("%d %d", a + b, c);
	//在打印c的时候是按照%d的格式输出的，所以会发生整型提升，c是个正数，所以在前面补0，即00000000000000000000000000101100，即44
	//直接打印a + b就是直接将00000000000000000000000100101100输出 即300
	return 0;
}
/*
	哪些情况会发生整型提升？
	表达式中包含小于 int 类型的变量：当表达式中包含 char、short 等小于 int 的类型时，这些类型会提升为 int（或 unsigned int，视具体情况而定）。

	赋值操作：当小于 int 类型的数据（如 char 或 short）被赋值给 int 类型的变量时，会发生整型提升。

	参数传递时的提升：当 char 或 short 类型的变量作为参数传递给函数，并且函数的参数类型为 int 时，编译器会将这些变量提升为 int。特别是，当没有提供参数类型（如 printf("%d", c); 中 char 变量 c），c 会被提升为 int。

	返回值的提升：当返回类型为 int 的函数返回 char 或 short 类型的值时，也会进行提升，将它们转换为 int。

	单目运算符：在使用单目运算符（如 +、- 或 ~）时，也会发生整型提升。例如，对于表达式 -c，如果 c 是 char 或 short 类型，c 会提升为 int 后再进行运算。
*/


/*
int main()
{
	unsigned int a = 0x1234;
	//a存入内存中是 34 12 00 00 （地址由低到高）
	unsigned char b = *(unsigned char*)&a;
	//b从低地址开始读，读一个字节，就是0x34
	printf("%x\n", b);
	return 0;
}
//程序读取内存是从低地址读到高地址
//从低地址到高地址读取是一种简化硬件设计、优化内存读取效率的方式。它符合内存的线性布局特点，与 CPU 的指令集设计和缓存机制相配合，使得内存访问更加快速高效。
//大小端字节序强调的是字节的顺序
*/

/*
void printYangHuiTriangle(int n) {
	int arr[n][n];

	// 初始化杨辉三角数组
	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;   // 每行第一个元素是1
		arr[i][i] = 1;   // 每行最后一个元素是1
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];  // 中间元素
		}
	}

	// 打印杨辉三角
	for (int i = 0; i < n; i++) {
		// 输出空格使三角形居中
		for (int k = 0; k < n - i - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("请输入要打印的行数：");
	scanf("%d", &n);
	printYangHuiTriangle(n);
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

void printYangHuiTriangle(int n) {
	int** arr = (int**)malloc(n * sizeof(int*));//用malloc模拟变长数组
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc((i + 1) * sizeof(int));
	}

	// 初始化杨辉三角数组
	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	// 打印杨辉三角
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// 释放动态分配的内存
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}

int main() {
	int n;
	printf("请输入要打印的行数：");
	scanf("%d", &n);
	printYangHuiTriangle(n);
	return 0;
}
*/

//注意char* p = "abcdef" p中存的是a的地址，*p是指a，但是printf("%s",p)输出的是abcdef，
//strlen(p)求的也是字符串abcdef的长度，因为这两个函数都是从p的地址出发，一直向后找到\0