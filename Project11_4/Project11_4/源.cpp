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

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ���� arr[j] �� arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 ,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ������: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("����������: ");
    printArray(arr, n);

    return 0;
}