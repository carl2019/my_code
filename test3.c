/*1.��д������ 
unsigned int reverse_bit(unsigned int value); 
��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 
�磺 
��32λ������25���ֵ�������и�λ�� 
00000000000000000000000000011001 
��ת�󣺣�2550136832�� 
10011000000000000000000000000000 
���������أ� 
2550136832 */
#include <stdio.h>
#include <math.h>
unsigned int reverse_bits(unsigned int n)
{
	int i = 0;
	unsigned int sum = 0;
	for(i = 0; i < 32; i++)
	{
		sum += ((n>>i) & 1) * pow(2, 31-i);
	}
    return sum;
}

int main()
{ 
	int n;
	scanf("%d",&n);
	printf("%u\n", reverse_bits(n));
	return 0;
}

//2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
#include <stdio.h>
int avg(int a, int b)
{
	return (a+b) >> 1;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
	printf("%d\n",avg(a,b));
	return 0;
}

//3.���ʵ�֣�һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
#include <stdio.h>
int main()
{
	int i = 0;
	int ret = 0;
	int a[] = {1,2,3,4,1,2,3};
	for(i=0; i<9; i++)
	{
		ret ^= a[i];
	}
	printf("%d", ret);
	return 0;
}

//4.��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�󣺲���ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ��� 
#include <stdio.h>
#include <assert.h>
int strlen (char* str)
{
	int count = 0;
	while(*str++)
	{
		count++;
	}
	return count;
}

void reverse_str(char* start, char* end)
{
	assert(start && end);
	while(start < end)
	{
		char tmp = 0;
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void reverse(char* str)
{
	char* ret = str;
	int len = strlen(str);
	reverse_str(str, str + len -1);

	while(*str != '\0')
	{
		char *left = str;
		char *right = left;
		while((*right != ' ') && (*right !='\0'))
		{
			right++;
		}
		reverse_str(left, right -1);
		if(*right != '\0')
		{
			str = right +1;
		}
		else
		{
			str = right;
		}
	}
	return ret;
}

int main()
{
	char arr[] = "student a  am i ";
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}

/*5.��������ʹ����ȫ����λ��ż��ǰ�档 
����һ���������飬ʵ��һ������,�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
����ż��λ������ĺ�벿�֡�*/ 
#include <stdio.h>
void Exchange(int arr[], int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	while(left < right)
	{
		while((left < right) && (*left)%2 != 0)
		{
			left++;
		}
		while((left < right) && (*right)%2 == 0)
		{
			right--;
		}
		if(left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	Exchange(arr, sz);
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}