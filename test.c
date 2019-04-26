#define _CRT_SECURE_NO_WARNINGS

//1.在屏幕上输出以下图案： 
//      * 
//     *** 
//    ***** 
//   ******* 
//  ********* 
// *********** 
//************* 
// *********** 
//  ********* 
//   ******* 
//    ***** 
//     *** 
//      * 
#include <stdio.h>
int main()
{
    int i = 0;
	int line = 0; //控制上半部分打印的行数
	scanf("%d", &line);
	for(i = 0; i < line; i++)
	{
		int j = 0;
		for(j = 0; j < line-1-i; j++)
		{
			printf(" ");
		}
		for(j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i = 0; i < line-1; i++)
	{
		int j = 0;	
		for(j = 0; j < i+1; j++)
		{
			printf(" ");
		}
		for(j = 0; j < 2*(line-1-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

////2.求出0～999之间的所有“水仙花数”并输出。
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int i = 0;
//	for(i = 0; i <= 999; i++)
//	{	
//		//计算位数
//        int count = 1;
//		int sum = 0;
//		int tmp = i;
//		while(tmp/10)
//		{
//			count++;
//			tmp = tmp/10;
//		}
//		//计算次方和
//		tmp = i;
//		while(tmp)
//		{
//			sum += pow(tmp%10, count);
//			tmp = tmp/10;
//		}
//		//判断是否为水仙花数
//		if(sum == i)
//			printf("%d ",i);
//	}
//	return 0;
//}
//
////3.求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222 
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int sum = 0; 
//	int tmp = a;
//	int count = 0;
//	scanf("%d%d",&a,&count);
//	while(count--)
//	{
//		tmp = tmp*10+a;
//	    sum += tmp;    
//	}
//	printf("%d ",sum);
//	return 0;
//}
//
////4.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。 
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    int ch = 0;
//	int count = 0;
//	while((ch = getchar()) != EOF)
//	{
//		if('{' == ch)
//		{
//			count++;
//		}
//		else if(('}' == ch) && (count != 0))
//		{
//			count--;
//		}
//		else if(('}' == ch) && (count == 0))
//		{
//			printf("false\n");
//			return 0;
//		}
//	}
//    if(count == 0)
//	{
//        printf("true\n");
//	}
//	else
//	{
//		printf("false\n");
//	}
//	return 0;
//}