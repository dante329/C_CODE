#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
int main()
{
	unsigned char a = 200;
	//200�Ķ�����������00000000000000000000000011001000
	//����Ҫ����a�У�һ�����ڴ�����ִ���һ��С�ڴ�ı����У��ͻᷢ���ضϣ�ֻ����11001000
	unsigned char b = 100;
	//����01100100
	unsigned char c = 0;

	c = a + b;
	//��������������ͱ� int ��С������ char �� short������ô���ǻᱻ������ int ���ͣ��� unsigned int����� int ������������Щֵ��
	//��ִ�� a + b ʱ��a �� b ���ȱ�����Ϊ int ���ͣ�Ȼ���ٽ�����Ӳ�����
	//00000000000000000000000011001000 -a
	//00000000000000000000000001100100 -b
	//00000000000000000000000100101100 a+b
	//����cʱ�ᷢ���ض� 00101100 -c
	printf("%d %d", a + b, c);
	//�ڴ�ӡc��ʱ���ǰ���%d�ĸ�ʽ����ģ����Իᷢ������������c�Ǹ�������������ǰ�油0����00000000000000000000000000101100����44
	//ֱ�Ӵ�ӡa + b����ֱ�ӽ�00000000000000000000000100101100��� ��300
	return 0;
}
/*
	��Щ����ᷢ������������
	���ʽ�а���С�� int ���͵ı����������ʽ�а��� char��short ��С�� int ������ʱ����Щ���ͻ�����Ϊ int���� unsigned int���Ӿ��������������

	��ֵ��������С�� int ���͵����ݣ��� char �� short������ֵ�� int ���͵ı���ʱ���ᷢ������������

	��������ʱ���������� char �� short ���͵ı�����Ϊ�������ݸ����������Һ����Ĳ�������Ϊ int ʱ���������Ὣ��Щ��������Ϊ int���ر��ǣ���û���ṩ�������ͣ��� printf("%d", c); �� char ���� c����c �ᱻ����Ϊ int��

	����ֵ������������������Ϊ int �ĺ������� char �� short ���͵�ֵʱ��Ҳ�����������������ת��Ϊ int��

	��Ŀ���������ʹ�õ�Ŀ��������� +��- �� ~��ʱ��Ҳ�ᷢ���������������磬���ڱ��ʽ -c����� c �� char �� short ���ͣ�c ������Ϊ int ���ٽ������㡣
*/


/*
int main()
{
	unsigned int a = 0x1234;
	//a�����ڴ����� 34 12 00 00 ����ַ�ɵ͵��ߣ�
	unsigned char b = *(unsigned char*)&a;
	//b�ӵ͵�ַ��ʼ������һ���ֽڣ�����0x34
	printf("%x\n", b);
	return 0;
}
//�����ȡ�ڴ��Ǵӵ͵�ַ�����ߵ�ַ
//�ӵ͵�ַ���ߵ�ַ��ȡ��һ�ּ�Ӳ����ơ��Ż��ڴ��ȡЧ�ʵķ�ʽ���������ڴ�����Բ����ص㣬�� CPU ��ָ���ƺͻ����������ϣ�ʹ���ڴ���ʸ��ӿ��ٸ�Ч��
//��С���ֽ���ǿ�������ֽڵ�˳��
*/

/*
void printYangHuiTriangle(int n) {
	int arr[n][n];

	// ��ʼ�������������
	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;   // ÿ�е�һ��Ԫ����1
		arr[i][i] = 1;   // ÿ�����һ��Ԫ����1
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];  // �м�Ԫ��
		}
	}

	// ��ӡ�������
	for (int i = 0; i < n; i++) {
		// ����ո�ʹ�����ξ���
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
	printf("������Ҫ��ӡ��������");
	scanf("%d", &n);
	printYangHuiTriangle(n);
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

void printYangHuiTriangle(int n) {
	int** arr = (int**)malloc(n * sizeof(int*));//��mallocģ��䳤����
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc((i + 1) * sizeof(int));
	}

	// ��ʼ�������������
	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	// ��ӡ�������
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	// �ͷŶ�̬������ڴ�
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}

int main() {
	int n;
	printf("������Ҫ��ӡ��������");
	scanf("%d", &n);
	printYangHuiTriangle(n);
	return 0;
}
*/

//ע��char* p = "abcdef" p�д����a�ĵ�ַ��*p��ָa������printf("%s",p)�������abcdef��
//strlen(p)���Ҳ���ַ���abcdef�ĳ��ȣ���Ϊ�������������Ǵ�p�ĵ�ַ������һֱ����ҵ�\0