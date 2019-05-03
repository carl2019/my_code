//1.计算1/1-1/2+1/3-1/4+1/5......+1/99-1/100的值
#include<stdio.h>
int main()
{
	int i = 0;
	double sum = 0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += 1.0 / i*flag; //浮点数除法必须有一个数是浮点数
		//sum = sum + 1.0/i*flag;
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}

//2.将数组A和数组B的内容进行交换
#include<stdio.h>
int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 6, 7, 8, 9, 10 };
	int tmp = 0;
	int i = 0;
	for (i = 0; i <= 5; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0; i <= 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
void print_arr(int arr[5], int sz)
{
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 6, 7, 8, 9, 10 };
	int tmp = 0;
	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i<sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	print_arr(arr1, sz);
	print_arr(arr2, sz);
	return 0;
}

//3.实现一个函数，打印乘法表，行列自己指定，如果输入的是9，就打印9*9，输入12，就打印12*12
#include<stdio.h>
void printf_table(int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		{
			for (j = 1; j <= i; j++)
			{
				printf("%d*%d=%2d ", i, j, i*j);
			}
			printf("\n");
		}
	}
}

int main()
{
	int line = 0;
	scanf("%d", &line);
	printf_table(line);
	return 0;
}
