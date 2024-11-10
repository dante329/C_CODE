#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
//KMP算法

/*
包含两部分：
1.KMP主体函数
2.next数组生成函数
*/

//next数组生成函数，匹配失败后j跳转的逻辑
void GetNext(char* sub , int* next , int lenSub)
{
	next[0] = -1;
	next[1] = 0;
	//0   1   2   3   4   5		i
	//a   b   c   a   b   c		sub[]
	//-1  0   0   1   2   3		next[]
	int i = 2;
	int k = 0;
	while (i < lenSub)
	{
		if (k == -1 || sub[i - 1] == 0)//sub[i - 1] == sub[next[i - 1]]
		{
			next[i] = k + 1;
			i++;
			k++;//k保存前一项的k值
		}
		else
		{
			k = next[k];
		}
	}
}

//KMP主体函数，匹配的逻辑
//	返回类型为char*
//char* KMP(char* str , char* sub , int start)
//{
//	assert(str != NULL && sub != NULL);
//	int lenStr = strlen(str);
//	int lenSub = strlen(sub);
//	if (lenStr == 0 || lenSub == 0) return -1;
//	if (start<0 || start>lenStr) return -1;
//
//	//next数组在j匹配失败需要跳转前就已经准备好了
//	int* next = (int*)malloc(sizeof(int) * lenSub);
//	assert(next != NULL);//判断地址分配成功
//
//	GetNext(sub,next,lenSub);
//
//	int i = start;
//	int j = 0;
//
//	while (i < lenStr && j < lenSub)
//	{
//		if (str[i] == sub[j])
//		{
//			i++;
//			j++;//todo: 省略到if中
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j >= lenSub)//j == '\0'
//	{
//		return str + i - j;//返回的是sub第一次在str中出现的地址，匹配成功时i向回跳转j个单位就是sub在str中的首次开始位置
//	}
//	return NULL;
//}

//	返回类型为int
int KMP(char* str, char* sub, int start)
{
	assert(str != NULL && sub != NULL);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0) return -1;
	if (start<0 || start>lenStr) return -1;

	//next数组在j匹配失败需要跳转前就已经准备好了
	int* next = (int*)malloc(sizeof(int) * lenSub);
	assert(next != NULL);//判断地址分配成功

	GetNext(sub, next, lenSub);

	int i = start;
	int j = 0;

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])//忘记写j == -1这个条件，这个bug真是改了半天
		{
			i++;
			j++;//todo: 省略到if中
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lenSub)//j == '\0'
	{
		return i - j;//返回的是sub第一次在str中出现的地址，匹配成功时i向回跳转j个单位就是sub在str中的首次开始位置
	}
	return -1;
}

int main()
{
	char str[] = "hello world dante";
	char sub[] = "world";
	printf("Substring found at index: %d\n", KMP(str, sub, 0));

	return 0;
}


//ChatGpt给出的算法

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//void GetNext(char* sub, int* next, int lenSub) {
//	next[0] = -1;
//	int i = 1;
//	int k = -1;
//	while (i < lenSub) {
//		if (k == -1 || sub[i - 1] == sub[k]) {
//			k++;
//			next[i] = k;
//			i++;
//		}
//		else {
//			k = next[k];
//		}
//	}
//
//	// 输出 next 数组，检查是否正确
//	printf("Next array: ");
//	for (int j = 0; j < lenSub; j++) {
//		printf("%d ", next[j]);
//	}
//	printf("\n");
//}
//
//int KMP(char* str, char* sub, int start) {
//	assert(str != NULL && sub != NULL);
//	int lenStr = strlen(str);
//	int lenSub = strlen(sub);
//	if (lenStr == 0 || lenSub == 0) return -1;
//	if (start < 0 || start > lenStr) return -1;
//
//	int* next = (int*)malloc(sizeof(int) * lenSub);
//	assert(next != NULL);
//
//	GetNext(sub, next, lenSub);
//
//	int i = start;
//	int j = 0;
//
//	while (i < lenStr && j < lenSub) {
//		if (str[i] == sub[j]) {
//			i++;
//			j++;
//		}
//		else if (j == 0) {
//			i++;
//		}
//		else {
//			j = next[j];
//		}
//	}
//	free(next);
//
//	if (j == lenSub) {
//		return i - j; // 返回匹配的起始位置
//	}
//	return -1; // 未找到匹配
//}
//
//int main() {
//	char str[] = "hello world dante";
//	char sub[] = "world";
//	int position = KMP(str, sub, 0);
//
//	if (position != -1) {
//		printf("Substring found at index: %d\n", position);
//	}
//	else {
//		printf("Substring not found.\n");
//	}
//
//	return 0;
//}