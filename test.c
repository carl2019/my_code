#define _CRT_SECURE_NO_WARNINGS

//1.����Ļ���������ͼ���� 
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
	int line = 0; //�����ϰ벿�ִ�ӡ������
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

////2.���0��999֮������С�ˮ�ɻ������������
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    int i = 0;
//	for(i = 0; i <= 999; i++)
//	{	
//		//����λ��
//        int count = 1;
//		int sum = 0;
//		int tmp = i;
//		while(tmp/10)
//		{
//			count++;
//			tmp = tmp/10;
//		}
//		//����η���
//		tmp = i;
//		while(tmp)
//		{
//			sum += pow(tmp%10, count);
//			tmp = tmp/10;
//		}
//		//�ж��Ƿ�Ϊˮ�ɻ���
//		if(sum == i)
//			printf("%d ",i);
//	}
//	return 0;
//}
//
////3.��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222 
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
////4.��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡� 
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