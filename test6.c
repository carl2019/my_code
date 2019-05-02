//1.判断一个数是否为奇数
#include<stdio.h>
int main()
{
	int a=0;
	printf("请输入一个整数：");
    scanf("%d",&a);
	if(a%2==1)
	{
		//printf("%d ",a);
		printf("%d是奇数",a);
	}
	else
		printf("%d不是奇数",a);
	return 0;
}

//2.使用函数实现两个数的交换
#include<stdio.h>
void swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d%d", &num1, &num2);
	swap(&num1, &num2);
	printf("num1=%d num2=%d", num1, num2);
	return 0;
}

//不用函数实现两个数的交换
#include<stdio.h>
int main()
{
	int num1 = 10;
	int num2 = 20;
	printf("num1 = %d num2 = %d\n", num1, num2);
	num1 = num1^num2;
	num2 = num1^num2;
	num1 = num1^num2;
	printf("num1 = %d num2 = %d\n", num1, num2);
	return 0;
}

#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int tmp = 0;

	scanf("%d %d",&a,&b);
	printf("a = %d b = %d\n",a,b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a = %d b = %d\n",a,b);
	return 0;
}

//3.三个数中求最大
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10] = {0};
	int i = 0;
	int max = 0;
	for(i=0; i<10; i++)
	{
		scanf("%d",&arr[i]);
	}

    max = arr[0];
	for(i=1; i<10; i++)
	{
		if(arr[i] > max)
			max = arr[i];

	}
	printf("max = %d\n",max);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int tmp = 0;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if(a<c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if(b<c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("a = %d b = %d c = %d\n",a,b,c);
	return 0;
}

#include<stdio.h>
int main()
{
	int a = 12;
	int b = 20;
	int c = 0;
	while(a%b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("%d\n",b);
	return 0;
}