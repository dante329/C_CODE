#define _CRT_SECURE_NO_WARNINGS



//int main() 
//{
//	char arr[3];
//	char tem;
//	int i,j;
//	while (scanf("%c %c %c", &arr[0], &arr[1], &arr[2]) == 3)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			for (i = 0; i < 2; i++)
//			{
//				if (arr[i] > arr[i + 1])
//				{
//					tem = arr[i];
//					arr[i] = arr[i + 1];
//					arr[i + 1] = tem;
//				}
//			}
//			
//		}
//		for (j = 0; j < 3; j++)
//		{
//			printf("%c ", arr[j]);
//		}
//		printf("\n");
//		
//		getchar();
//	}
//	
//	return 0;
//}

//
//int main()
//{
//	char a[4], temp;
//	while (scanf("%c %c %c", &a[0], &a[1], &a[2]) != EOF)
//	{
//		if (a[0] > a[1])
//		{
//			temp = a[0];
//			a[0] = a[1];
//			a[1] = temp;
//		}
//		if (a[1] > a[2])
//		{
//			temp = a[1];
//			a[1] = a[2];
//			a[2] = temp;
//		}
//		if (a[0] > a[1])
//		{
//			temp = a[0];
//			a[0] = a[1];
//			a[1] = temp;
//		}
//		printf("%c %c %c\n", a[0], a[1], a[2]);
//		getchar();        //接收回车……3
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	char a[10001];
//	int x, i;
//	while (cin >> a)
//	{
//		x = strlen(a);
//		sort(a, a + x);
//		for (i = 0; i < x - 1; i++)
//			cout << a[i] << ' ';
//		cout << a[x - 1] << endl;
//	}
//
//	return 0;
//}

#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int main() 
//{
//	double x1, x2, y1, y2;
//	double dis;
//	while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2)!=EOF)
//	{
//		dis = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
//		printf("%.2f", dis);
//	}
//
//}

//int main()
//{
//	double a;
//	while (scanf("%lf", a) != EOF)
//	{
//		
//	}
//}

//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];
//	int high;
//};
//
//void print(struct Peo* sp)
//{
//	printf("%s %s %s %d\n", sp->name, sp->tele, sp->sex, sp->high);
//}
//int main()
//{
//	struct Peo p1 = { "张三","15272851897","男",192 };
//	print(&p1);
//	printf("%zu", sizeof(p1.name[1]));
//}


//int main()
//{
//	char name[]="张三";
//	printf("%s", name);
//	printf("%zu", sizeof name);
//}

//int sum_for_1(int n)
//{
//	int count = 0;
//	while (n) 
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	printf("%d",sum_for_1(i));
//}

/*int count_diff_bit(int m, int n)
{
	int count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
			count++;
	}
	return count;
}*/

//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	printf("%d\n", count_diff_bit(m, n));
//}

//int main()
//{
//	int y, m, d;
//	while (scanf("%d %d", &y, &m) == 2)
//	{
//		if (m < 1 || m>12)
//		{
//			printf("%s", "输入有误");
//		}
//		else if (m == 1 | m == 3 | m == 5 | m == 7 | m == 8 | m == 10 | m == 12)
//		{
//			printf("%d", 31);
//		}
//		else if (m == 2)
//		{
//			if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//			{
//				printf("%d", 28);
//			}
//			else
//			{
//				printf("%d", 29);
//			}
//		}
//		else
//		{
//			printf("%d", 30);
//		}
//		//getchar();
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1,m=2;
//	if(i&&m==2)
//	{	
//		printf("%s", "fuck");
//	}
//	return 0;
//}