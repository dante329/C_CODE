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
//	while (*dest)
//	{
//		dest++;
//	}
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