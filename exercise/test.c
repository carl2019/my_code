////���1-100֮�������
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//
//	for(i=1; i<=100; i+=2)
//	{
//		printf("%d ",i);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//
//	for(i=1; i<=100; i++)
//	{
//		if(i%2==1)
//			printf("%d ",i);
//	}
// return 0;
//}

//�ж�һ�����Ƿ�Ϊ����
//#include<stdio.h>
//int main()
//{
//	int a=0;
//	printf("������һ��������");
//    scanf("%d",&a);
//	if(a%2==1)
//	{
//		//printf("%d ",a);
//		printf("%d������",a);
//	}
//	else
//		printf("%d��������",a);
//	return 0;
//}

////100-200֮�������
//#include<stdio.h>
//int main()
//{
//	int i=0;
//	int count=0;
//	for(i=100;i<=200;i++)
//	{
//		int j=0;
//		for(j=2; j<i; j++)
//
//		{
//			if(i%j == 0)
//				break;
//		}
//		if(j>=i)
//		{
//			printf("%d  ",i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}

////1000-2000��֮�������
//#include <stdio.h>
//int main()
//{
//	int year=0;
//	int count=0;
//	for(year=1000;year<=2000;year++)
//	{
//		if(((year%4==0) && (year%100!=0)) ||(year%400==0))
//		{
//			
//			printf("%d ",year);
//			count ++;
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}

////�˷���
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i=0;
//	for(i=1;i<=9;i++)
//	{
//		int j=0;
//		for(j=1;j<=i;j++)
//		{
//			printf("%d*%d=%2d ",i,j,i*j);//����������λ�����Ҷ���
//			//printf("%d*%d=%-2d ",i,j,i*j);//����������λ���������
//		}
//		//����
//		printf("\n");
//	}
//    system("pause");   //Ҫ������������β��
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//
//	scanf("%d %d",&a,&b);
//	printf("a = %d b = %d\n",a,b);
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a = %d b = %d\n",a,b);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("num1 = %d num2 = %d\n",num1,num2);
//	num1 = num1^num2;
//	num2 = num1^num2;
//	num1 = num1^num2;
//	printf("num1 = %d num2 = %d\n",num1,num2);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	int max = 0;
//	for(i=0; i<10; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//
//    max = arr[0];
//	for(i=1; i<10; i++)
//	{
//		if(arr[i] > max)
//			max = arr[i];
//
//	}
//	printf("max = %d\n",max);
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	scanf("%d %d %d",&a,&b,&c);
//	if(a<b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if(a<c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if(b<c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a = %d b = %d c = %d\n",a,b,c);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 12;
//	int b = 20;
//	int c = 0;
//	while(a%b)
//	{
//		c = a%b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n",b);
//	return 0;
//}

//1-100���������г��ֶ��ٴ�����9
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for(i = 1; i <= 100; i++)
//	{
//		if(i%10 == 9)
//			count++;
//		if(i/10 == 9)
//			count++;
//	}
//	printf("%d\n",count);
//	return 0;
//}

//����1/1-1/2+1/3-1/4+1/5......+1/99-1/100��ֵ
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for(i = 1; i <= 100; i++)
//	{
//		sum += 1.0/i*flag; //����������������һ�����Ǹ�����
//		//sum = sum + 1.0/i*flag;
//		flag = -flag;	
//	}
//	printf("%lf\n",sum);
//	return 0;
//}

//������A������B�����ݽ��н���
//#include<stdio.h>
//
//int main()
//{
//	int arr1[5] = {1,2,3,4,5};
//	int arr2[5] = {6,7,8,9,10};
//	int tmp = 0;
//	int i = 0;
//	for(i = 0; i <= 5; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for(i = 0; i <= 5; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	printf("\n");
//	for(i = 0; i <= 5; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}

//������A������B�����ݽ��н���
//#include<stdio.h>
//void print_arr(int arr[5],int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[5] = {1, 2, 3, 4, 5};
//	int arr2[5] = {6, 7, 8, 9, 10};
//	int tmp = 0;
//	int i = 0;
//	int sz = sizeof(arr1)/sizeof(arr1[0]);
//	for(i=0; i<sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	print_arr(arr1,sz);
//	print_arr(arr2,sz);
//	return 0;
//}

//1.ʵ��һ����������ӡ�˷��������Լ�ָ��������������9���ʹ�ӡ9*9������12���ʹ�ӡ12*12
//#include<stdio.h>
//void printf_table(int n)
//{
//	int i = 0;
//	for(i=1; i<=n; i++)
//	{
//		int j = 0;
//		{
//			for(j=1; j<=i; j++)
//			{
//				printf("%d*%d=%2d ",i,j,i*j);
//			}
//			printf("\n");
//		}
//	}
//}
//int main()
//{
//	int line = 0;
//	scanf("%d",&line);
//	printf_table(line);
//	return 0;
//}

//ʹ�ú���ʵ���������Ľ���
//#include<stdio.h>
//void swap(int* px,int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d",&num1,&num2);
//	swap(&num1,&num2);
//	printf("num1=%d num2=%d", num1, num2);
//	return 0;
//}

//ʵ��һ�������ж�year�ǲ�������
//#include<stdio.h>
//int is_leap_year(int year)
//{
//	return ((0 == year%4) && (0 != year%100)) || (0 == year%400);		
//}
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for(year=1000; year<=2000; year++)
//	{
//		if(1 == is_leap_year(year))
//		{
//			count++;
//			printf("%d ",year);
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}

//����һ������ ʵ��init()��ʼ������ ʵ��empty()������� ʵ��reverse()�������Ԫ�ص����� 
//�Լ����Ԫ�صĲ���������ֵ
//#include<stdio.h>
//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//void Empty(int arr[], int sz)
//{
//	int i = 0;
//	for(i=0; i<sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz-1;
//
//	while(left<right)
//	{
//		int tmp = arr[left];
//	    arr[left] = arr[right];
//	    arr[right] = tmp;
//	    left++;
//	    right--;
//	}
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	
//	Init(arr, sz);
//	Print(arr, sz);
//	Reverse(arr, sz);
//	Print(arr, sz);
//	Empty(arr, sz);
//	Print(arr, sz);
//	return 0;
//}

//ʵ��һ���������ж�һ�����ǲ�������
//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for(j=2; j<=sqrt(n); j++)
//	{
//		if(n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//void main()
//{
//	int i;
//	scanf("%d",&i);
//	if(is_prime(i))
//		printf("%d������\n",i);
//	else
//		printf("%d��������\n",i);
//}

//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (1 == is_prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d\n", count);
//	return 0;
//}