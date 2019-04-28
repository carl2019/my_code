/*1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
�ݹ飺1.�Լ������Լ�  2.Ҫ�г���
쳲��������У�
f(1) = f(2) = 1    f(n) = f(n-1) + f(n-2)*/
#include <stdio.h>
int fab(int n)
{
    int fn1 = 1;
	int fn2 = 1;
	int ret = 0;
	int i = 0;
	if(n == 1 || n == 2)
	{
		return 1;
	}
	for(i = 3; i <= n; i++)
	{
		ret = fn1 + fn2;
		fn2 = fn1;
		fn1 = ret;
	}
	return ret;
}

int fab_r(int n)
{
	if(n == 1 || n == 2)
	{
		return 1;
	}
	return fab_r(n-1) + fab_r(n-2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d: %d\n", n, fab(n));
	printf("%d: %d\n", n, fab_r(n));
	return 0;
}

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
#include <stdio.h>
int func(int n, int k)
{
	if(k <1)
	{
		return 1;
	}
	return n * func(n, k-1);
}

int main()
{
	int n;
	int k;
	scanf("%d%d", &n, &k);
	printf("%d", func(n, k));
	return 0;
}

/*3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19 */
#include <stdio.h>
int DigitSum(int n)
{
	if(n < 10)
	{
		return n;
	}
	return n%10 + DigitSum(n/10);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", DigitSum(n));
	return 0;
}

/*4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
#include <stdio.h>
#include <assert.h>
char* reverse_string(char* str)
{
	assert(str != NULL);
	if(*str != '\0')
	{
		str++;
	    reverse_string (str);
		printf("%c", *(str-1));	
	}
	return str;
}

int main()
{
	char str1[] = "abcdef";
	char* ret = reverse_string(str1);
	return 0;
}

//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
#include <stdio.h>
#include <assert.h>
int my_strlen1(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while(*str)
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(const char* str)
{
	int count = 0;
	assert(str != NULL);
	if(*str == '\0')
	{
		return 0;
	}
	return 1+my_strlen2(str+1);
}

int main()
{
	char str1[] = "abcdefg";
	int ret1 = my_strlen1(str1);
	int ret2 = my_strlen2(str1);
	printf("%d %d", ret1, ret2);
	return 0;
}

//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
#include <stdio.h>
int func_r(int n)
{
	if(n < 2)
	{
		return n;
	}
	return n * func_r(n - 1);
}

int func(int n)
{
	int ret = 1;
	int i = 0;
	for(i = 1; i <= n; i++)
	{
		ret = ret * i;
	}
	return ret; 
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d %d %d", n, func(n), func_r(n));
	return 0;
}

//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
#include <stdio.h>
int print(int n)
{
	if(n > 9)
	{
		print(n/10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int n;
	scanf("%d", &n);
	print(n);
	return 0;
} 