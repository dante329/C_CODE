#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
//KMP�㷨

/*
���������֣�
1.KMP���庯��
2.next�������ɺ���
*/

//next�������ɺ�����ƥ��ʧ�ܺ�j��ת���߼�
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
			k++;//k����ǰһ���kֵ
		}
		else
		{
			k = next[k];
		}
	}
}

//KMP���庯����ƥ����߼�
//	��������Ϊchar*
//char* KMP(char* str , char* sub , int start)
//{
//	assert(str != NULL && sub != NULL);
//	int lenStr = strlen(str);
//	int lenSub = strlen(sub);
//	if (lenStr == 0 || lenSub == 0) return -1;
//	if (start<0 || start>lenStr) return -1;
//
//	//next������jƥ��ʧ����Ҫ��תǰ���Ѿ�׼������
//	int* next = (int*)malloc(sizeof(int) * lenSub);
//	assert(next != NULL);//�жϵ�ַ����ɹ�
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
//			j++;//todo: ʡ�Ե�if��
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	if (j >= lenSub)//j == '\0'
//	{
//		return str + i - j;//���ص���sub��һ����str�г��ֵĵ�ַ��ƥ��ɹ�ʱi�����תj����λ����sub��str�е��״ο�ʼλ��
//	}
//	return NULL;
//}

//	��������Ϊint
int KMP(char* str, char* sub, int start)
{
	assert(str != NULL && sub != NULL);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0) return -1;
	if (start<0 || start>lenStr) return -1;

	//next������jƥ��ʧ����Ҫ��תǰ���Ѿ�׼������
	int* next = (int*)malloc(sizeof(int) * lenSub);
	assert(next != NULL);//�жϵ�ַ����ɹ�

	GetNext(sub, next, lenSub);

	int i = start;
	int j = 0;

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])//����дj == -1������������bug���Ǹ��˰���
		{
			i++;
			j++;//todo: ʡ�Ե�if��
		}
		else
		{
			j = next[j];
		}
	}
	free(next);
	if (j >= lenSub)//j == '\0'
	{
		return i - j;//���ص���sub��һ����str�г��ֵĵ�ַ��ƥ��ɹ�ʱi�����תj����λ����sub��str�е��״ο�ʼλ��
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


//ChatGpt�������㷨

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
//	// ��� next ���飬����Ƿ���ȷ
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
//		return i - j; // ����ƥ�����ʼλ��
//	}
//	return -1; // δ�ҵ�ƥ��
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