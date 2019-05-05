//1.实现一个函数判断year是不是闰年
#include<stdio.h>
int is_leap_year(int year)
{
	return ((0 == year%4) && (0 != year%100)) || (0 == year%400);		
}

int main()
{
	int year = 0;
	int count = 0;
	for(year=1000; year<=2000; year++)
	{
		if(1 == is_leap_year(year))
		{
			count++;
			printf("%d ",year);
		}
	}
	printf("\ncount=%d\n",count);
	return 0;
}

//2.实现一个函数，判断一个数是不是素数
#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int j = 0;
	for(j=2; j<=sqrt(n); j++)
	{
		if(n%j == 0)
			return 0;
	}
	return 1;
}

void main()
{
	int i;
	scanf("%d",&i);
	if(is_prime(i))
		printf("%d是素数\n",i);
	else
		printf("%d不是素数\n",i);
}

#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int j = 0;
	for (j = 2; j <= sqrt(n); j++)
	{
		if (n%j == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		if (1 == is_prime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount=%d\n", count);
	return 0;
}

//4.创建一个数组 实现init()初始化数组 实现empty()清空数组 实现reverse()完成数组元素的逆置 
//自己设计元素的参数、返回值
#include<stdio.h>
void Init(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		arr[i] = i;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Empty(int arr[], int sz)
{
	int i = 0;
	for(i=0; i<sz; i++)
	{
		arr[i] = 0;
	}
}

void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz-1;

	while(left<right)
	{
		int tmp = arr[left];
	    arr[left] = arr[right];
	    arr[right] = tmp;
	    left++;
	    right--;
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	
	Init(arr, sz);
	Print(arr, sz);
	Reverse(arr, sz);
	Print(arr, sz);
	Empty(arr, sz);
	Print(arr, sz);
	return 0;
}