#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

//11_07 字符串函数


//01 strlen 求字符串长度
//参数 size_t strlen ( const char * str );

//三种方法模拟实现strlen
//1.while循环
//size_t my_strlen1(const char* p)
//{
//	assert(p);
//	size_t count = 0;
//	while (*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
////2.递归
//size_t my_strlen2(const char* p)
//{
//	size_t count = 0;
//	if(*p)
//	{
//		count++;
//		return count + my_strlen2(p + 1);
//	}
//}
////不创建临时变量计数器的递归
//size_t my_strlen2_1(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen2_1(str + 1);
//}
////3.指针-指针
//size_t my_strlen3(const char* s)
//{
//	assert(s);
//	char* p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;//p最后停在了\0的位置
//}
//int main()
//{
//	char* p = "abcdef";
//	printf("%zu",my_strlen3(p));
//	return 0;
//}

//strcpy

//源字符串必须以 '\0' 结束。
//会将源字符串中的 '\0' 拷⻉到⽬标空间。
//⽬标空间必须⾜够⼤，以确保能存放源字符串。
//⽬标空间必须可修改。//dest不能是常量区的字符串 不可被修改

//模拟实现strcpy
//无返回值
//void my_strcpy(char* dest,const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* p1 = src;
//	char* p2 = dest;
//	while (*p1)
//	{
//		*p2++ = *p1++;
//		/*p2++;
//		p1++;*/
//	}
//	*p2= *p1;
//}

//返回dest的首元素地址
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*src)
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//	return ret;
//}
//
////更简洁
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*dest++ = *src++)//即完成赋值也进行判断 在C语言中 赋值表达式会返回赋给变量的值 这个表达式的返回值就是赋的值
//	//{
//		;//空语句
//	//}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20];
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//strcat 

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//strcmp

//模拟实现
//int my_strcmp(const char* str1, const char* str2)
//{
//	int ret = 0;
//	assert(str1 != NULL);
//	assert(str2 != NULL);//因为下面要对str1 str2解引用操作 所以一定要验证它们不为空指针
//	while (*str1 == *str2)
//	{
//	if (*str1 == '\0')
//		return 0;
//		str1++;
//		str2++;
//		}
//	return *str1 - *str2;
//}

//strncat

//函数实现
//char* __cdecl strncat(
//    char* front,
//    const char* back,
//    size_t count
//)
//{
//    char* start = front;
//
//    while (*front++)
//        ;
//    front--;
//
//    while (count--)
//        if ((*front++ = *back++) == 0)
//            return(start);
//
//    *front = '\0';
//    return(start);
//}

//strstr 
//char * strstr ( const char * str1, const char * str2);
//查找 str2 指向的字符串在 str1 指向的字符串中第⼀次出现的位置
//若找到返回子字符串第⼀次出现位置的指针 找不到返回NULL

//模拟实现
/* strstr example */
#include <stdio.h>
#include <string.h>
#include <assert.h>

//my_strstr()版本1
// 
//char* my_strstr(const char* str1, const char* str2)
//{
//	/*if (!*str2)
//	{
//		return NULL;
//	}*///如果str2是空指针那么肯定在str1里找不到，那么一定返回NULL
//	
//	//也可以这么写，用assert防止str1和str2传入空指针进入函数
//	assert(str1);
//	assert(str2);
//	
//	//因为我们要返回的是str2第一次被找到的地址，所以要先创建一个变量来保存str1
//	char* ret = str1;
//	char* s1 = str1;
//	char* s2 = str2;
//
//	//当*str1==*str2的时候，它们同时++继续判断（用到while循环），直到两种情况：1.他们不再相等，返回到ret+1的位置继续判断
//	//2.如果*str2判断到了\0那么return ret
//	while (*s1 != '\0' && *s2 != '\0')
//	{
//		ret = s1;
//		while (*s1 == *s2 && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return ret ;
//		}
//		s1 = ret + 1;
//	}
//	return 0;
//}

//有一定的逻辑错误
//1. 未重置 s2 指针 
//在 s1 和 s2 之间的比较失败后，没有将 s2 重置为 str2 的起始位置。这会导致接下来的比较不从 str2 的开头开始，影响结果。

//2. ret 指针的初始赋值和返回
//ret 是用于保存 str2 在 str1 中首次出现的位置的指针，但当前的代码将 ret 指向了 s1 的每一个字符位置，而不是在每次外层循环的开始处正确赋值。

//3. const 类型一致性
//str1 和 str2 都是 const char* ，为了确保类型一致性，s1 和 s2 也应为 const char* 类型。如果最终需要返回可修改的 char* ，可以在返回时进行转换。

//以下为版本2

//char* my_strstr(const char* str1, const char* str2) {
//    assert(str1);  // 检查 str1 非空
//    assert(str2);  // 检查 str2 非空
//
//    if (*str2 == '\0') {  // 如果 str2 是空字符串，直接返回 str1
//        return (char*)str1;
//    }
//
//    const char* s1 = str1;
//    const char* s2 = str2;
//
//    while (*s1 != '\0') {  // 遍历 str1
//        const char* start = s1;
//        s2 = str2;
//
//        // 比较 s1 和 s2 所指向的字符是否相等
//        while (*s1 == *s2 && *s2 != '\0') {
//            s1++;
//            s2++;
//        }
//
//        // 如果 s2 遍历到了结尾，说明完全匹配
//        if (*s2 == '\0') {
//            return (char*)start;
//        }
//
//        s1 = start + 1;  // 若不匹配，将 s1 移动到下一个字符
//    }
//
//    return NULL;  // 若未找到匹配，返回 NULL
//}

//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = my_strstr(str, "simple");
//	if (pch != NULL)
//		printf("%s\n", pch);
//	else
//		printf("查找的字符串不存在\n");
//	return 0;
//}

//char* my_strstr(const char* str1, const char* str2)
//{
//	/*if (!*str2)
//	{
//		return NULL;
//	}*///如果str2是空指针那么肯定在str1里找不到，那么一定返回NULL
//
//	//也可以这么写，用assert防止str1和str2传入空指针进入函数
//	assert(str1);
//	assert(str2);
//
//	//因为我们要返回的是str2第一次被找到的地址，所以要先创建一个变量来保存str1
//	//char* ret = str1;
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* ret = s1;
//	//当*str1==*str2的时候，它们同时++继续判断（用到while循环），直到两种情况：1.他们不再相等，返回到ret+1的位置继续判断
//	//2.如果*str2判断到了\0那么return ret
//	while (*ret != '\0')
//	{
//		s1 = ret;
//		s2 = str2;
//		while (*s1 == *s2 && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)ret;
//		}
//		ret++;
//	}
//	return 0;
//}


//strerror
//char * strerror ( int errnum );
//1. strerror 函数可以通过参数部分的 errnum 表⽰错误码，得到对应的错误信息，并且返回这
//个错误信息字符串⾸字符的地址。
//2. strerror 函数只针对标准库中的函数发⽣错误后设置的错误码的转换。
//3. strerror 的使⽤需要包含<string.h>
//errnum ：表⽰错误码
//这个错误码⼀般传递的是 errno 这个变量的值，在C语⾔有⼀个全局的变量叫： errno ，当库函数
//的调⽤发⽣错误的时候，就会讲本次错误的错误码存放在 errno 这个变量中，使⽤这个全局变量需要
//包含⼀个头⽂件 errno.h 。

//strtok
//char *strtok(char *str, const char *delim);
//参数：
//str：待分割的字符串。如果传入的是非空字符串指针，表示这是第一次调用 strtok。在后续调用中，需要传入 NULL 来继续从上一次分割的位置开始。
//delim：一个字符串，包含所有的分隔符字符。
//返回值：
//返回指向每个分割子串的指针。
//如果没有子串可返回（即分割到字符串结尾），则返回 NULL。

//函数演示

//用while循环实现分割
//int main() {
//    char str[] = "Hello world, this is strtok example.";
//    const char delim[] = " ,.";  // 分隔符为空格、逗号和句点
//
//    char* token = strtok(str, delim);  // 第一次调用传入字符串
//
//    while (token != NULL) {  // 继续分割直到返回 NULL
//        printf("%s\n", token);
//        token = strtok(NULL, delim);  // 后续调用传入 NULL
//    }
//
//    return 0;
//}
//
////使用 for 循环来实现 strtok 的分割操作，在 for 循环的初始化部分调用 strtok，然后在每次迭代中继续调用 strtok 直到返回 NULL
//int main() {
//    char str[] = "Hello world, this is a strtok example.";  // 要分割的字符串
//    const char delim[] = " ,.";  // 定义分隔符
//
//    // 用for循环分割字符串
//    for (char* token = strtok(str, delim); token != NULL; token = strtok(NULL, delim)) {
//        printf("%s\n", token);  // 输出每个子串
//    }
//
//    return 0;
//}
