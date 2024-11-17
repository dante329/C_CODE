#define _CRT_SECURE_NO_WARNINGS 1
/*
1. 为什么要有动态内存分配
我们已经掌握的内存开辟⽅式有：
int val = 20;//在栈空间上开辟四个字节
char arr[10] = {0};//在栈空间上开辟10个字节的连续空间
1
2
但是上述的开辟空间的⽅式有两个特点：
• 空间开辟⼤⼩是固定的。
• 数组在申明的时候，必须指定数组的⻓度，数组空间⼀旦确定了⼤⼩不能调整。
但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间⼤⼩在程序运⾏的时候才能知
道，那数组的编译时开辟空间的⽅式就不能满⾜了。
C语⾔引⼊了动态内存开辟，让程序员⾃⼰可以申请和释放空间，就⽐较灵活了。
2. malloc和free
2.1 malloc
C语⾔提供了⼀个动态内存开辟的函数：
1 void* malloc (size_t size);
这个函数向内存申请⼀块连续可⽤的空间，并返回指向这块空间的指针。
• 如果开辟成功，则返回⼀个指向开辟好空间的指针。
• 如果开辟失败，则返回⼀个 NULL 指针，因此malloc的返回值⼀定要做检查。
• 返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使⽤的时候使⽤者⾃
⼰来决定。
• 如果参数 size 为0，malloc 的⾏为是标准是未定义的，取决于编译器。
2.2 free
C语⾔提供了另外⼀个函数free，专⻔是⽤来做动态内存的释放和回收的，函数原型如下：
1 void free (void* ptr);//传过去是要释放的空间的起始地址
free函数⽤来释放动态开辟的内存。
• 如果参数 ptr 指向的空间不是动态开辟的，那free函数的⾏为是未定义的。
• 如果参数 ptr 是NULL指针，则函数什么事都不做。
malloc和free都声明在 stdlib.h 头⽂件中。
举个例⼦：
#include <stdio.h>
#include <stdlib.h>
int main()
{
int num = 0;
scanf("%d", &num);
int* ptr = NULL;
ptr = (int*)malloc(num*sizeof(int));
if(NULL != ptr)//判断ptr指针是否为空
{
int i = 0;
for(i=0; i<num; i++)
{
*(ptr+i) = 0；
}
}
free(ptr);//释放ptr所指向的动态内存
ptr = NULL;//是否有必要？
return 0;
}

3. calloc
C语⾔还提供了⼀个函数叫 calloc ， calloc 函数也⽤来动态内存分配。原型如下：
1 void* calloc (size_t num, size_t size);
• 函数的功能是为 num 个⼤⼩为 size 的元素开辟⼀块空间，并且把空间的每个字节初始化为0。
• 与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全
0。
举个例⼦：
#include <stdio.h>
#include <stdlib.h>
int main()
{
int *p = (int*)calloc(10, sizeof(int));
if(NULL != p)
{
int i = 0;
for(i=0; i<10; i++)
{
printf("%d ", *(p+i));
}
}
free(p);
p = NULL;
return 0;
}

输出结果：
1 0 0 0 0 0 0 0 0 0 0
所以如果我们对申请的内存空间的内容要求初始化，那么可以很⽅便的使⽤calloc函数来完成任务。
4. realloc
• realloc 函数的出现让动态内存管理更加灵活。
• 有时会我们发现过去申请的空间太⼩了，有时候我们⼜会觉得申请的空间过⼤了，那为了合理的使
⽤内存，我们⼀定会对内存的⼤⼩做灵活的调整。那 realloc 函数就可以做到对动态开辟内存⼤
⼩的调整。
函数原型如下：
1 void* realloc (void* ptr, size_t size);
• ptr 是要调整的内存空间的起始地址
• size 调整之后新⼤⼩
• 返回值为调整之后的内存空间的起始位置。
• 这个函数调整原内存空间⼤⼩的基础上，还会将原来内存中的数据移动到 新 的空间。
• realloc 在调整内存空间的是存在两种情况：
◦ 情况1：原有空间之后有⾜够⼤的空间
◦ 情况2：原有空间之后没有⾜够⼤的空间
情况1
当是情况1 的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发⽣变化。
情况2
当是情况2 的时候，原有空间之后没有⾜够多的空间时，扩展的⽅法是：在堆空间上另找⼀个合适⼤⼩
的连续空间来使⽤。这样函数返回的是⼀个新的内存地址。
由于上述的两种情况，realloc函数的使⽤就要注意⼀些。
#include <stdio.h>
#include <stdlib.h>
int main()
{
int *ptr = (int*)malloc(100);
if(ptr != NULL)
{
1
2
3
4
5
6
7
8
9 //业务处理
10 }
11 else
12 {
13 return 1;
14 }
15 //扩展容量
16
17 //代码1 - 直接将realloc的返回值放到ptr中
18 ptr = (int*)realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
19
20 //代码2 - 先将realloc函数的返回值放在p中，不为NULL，在放ptr中
21 int*p = NULL;
22 p = realloc(ptr, 1000);
23 if(p != NULL)
24 {
25 ptr = p;
26 }
27 //业务处理
28 free(ptr);
29 return 0;
30 }
5. 常⻅的动态内存的错误
5.1 对NULL指针的解引⽤操作
1 void test()
2 {
3 int *p = (int *)malloc(INT_MAX);
4 *p = 20;//如果p的值是NULL，就会有问题
5 free(p);
6 }
5.2 对动态开辟空间的越界访问
1 void test()
2 {
3 int i = 0;
4 int *p = (int *)malloc(10*sizeof(int));
5 if(NULL == p)
6 {
7 exit(EXIT_FAILURE);
8 }
9 for(i=0; i<=10; i++)
10 {
11 *(p+i) = i;//当i是10的时候越界访问
12 }
13 free(p);
14 }
5.3 对⾮动态开辟内存使⽤free释放
1 void test()
2 {
3 int a = 10;
4 int *p = &a;
5 free(p);//ok?
6 }
5.4 使⽤free释放⼀块动态开辟内存的⼀部分
1 void test()
2 {
3 int *p = (int *)malloc(100);
4 p++;
5 free(p);//p不再指向动态内存的起始位置
6 }
5.5 对同⼀块动态内存多次释放
1 void test()
2 {
3 int *p = (int *)malloc(100);
4 free(p);
5 free(p);//重复释放
6 }
5.6 动态开辟内存忘记释放（内存泄漏）
1 void test()
2 {
3 int *p = (int *)malloc(100);
4 if(NULL != p)
5 {
6 *p = 20;
7 }
8 }
9
10 int main()
11 {
12 test();
13 while(1);
14 }
忘记释放不再使⽤的动态开辟的空间会造成内存泄漏。
切记：动态开辟的空间⼀定要释放，并且正确释放。
6. 动态内存经典笔试题分析
6.1 题⽬1：
1 void GetMemory(char *p)
2 {
3 p = (char *)malloc(100);
4 }
5 void Test(void)
6 {
7 char *str = NULL;
8 GetMemory(str);
9 strcpy(str, "hello world");
10 printf(str);
11 }
12
13 int main()
14 {
15 Test();
16 return 0;
17 }
请问运⾏Test 函数会有什么样的结果？
答案：程序崩溃，内存泄露
6.2 题⽬2：
1 char *GetMemory(void)
2 {
3 char p[] = "hello world";
4 return p;
5 }
6 void Test(void)
7 {
8 char *str = NULL;
9 str = GetMemory();
10 printf(str);
11 }
12
13 int main()
14 {
15 Test();
16 return 0;
17 }
请问运⾏Test 函数会有什么样的结果？
答案：可能输出乱码。
6.3 题⽬3：
1 void GetMemory(char **p, int num)
2 {
3 *p = (char *)malloc(num);
4 }
5 void Test(void)
6 {
7 char *str = NULL;
8 GetMemory(&str, 100);
9 strcpy(str, "hello");
10 printf(str);
11 }
12
13 int main()
14 {
15 Test();
16 return 0;
17 }
请问运⾏Test 函数会有什么样的结果？
答案：内存泄露。
6.4 题⽬4：
1 void Test(void)
2 {
3 char *str = (char *) malloc(100);
4 strcpy(str, "hello");
5 free(str);
6 if(str != NULL)
7 {
8 strcpy(str, "world");
9 printf(str);
10 }
11 }
请问运⾏Test 函数会有什么样的结果？
答案：篡改动态内存区的内容，后果难以预料，⾮常危险。
因为 free(str); 之后 str 成为野指针， if(str != NULL) 语句不起作⽤。
柱：上⾯4个题⽬均出⾃⼀本书《⾼质量C/C++编程》，也是经常在编程中遇到的问题，所以后来就经
常拿来做笔试题⽬。*/