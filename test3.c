/*1.编写函数： 
unsigned int reverse_bit(unsigned int value); 
这个函数的返回值value的二进制位模式从左到右翻转后的值。 
如： 
在32位机器上25这个值包含下列各位： 
00000000000000000000000000011001 
翻转后：（2550136832） 
10011000000000000000000000000000 
程序结果返回： 
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

//2.不使用（a+b）/2这种方式，求两个数的平均值。 
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

//3.编程实现：一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
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

//4.有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student". 
//要求：不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。 
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

/*5.调整数组使奇数全部都位于偶数前面。 
输入一个整数数组，实现一个函数,来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
所有偶数位于数组的后半部分。*/ 
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