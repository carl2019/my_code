/*1.实现一个函数，可以左旋字符串中的k个字符。 
ABCD左旋一个字符得到BCDA 
ABCD左旋两个字符得到CDAB*/
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void left_rotate(char* str, int k)
{
	int len = 0;
	int i = 0;
	while(k--)
	{
		char tmp = *str;
		len = strlen(str);
		for(i = 0; i < len; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		*(str + len - 1) = tmp;
	}
}

int main()
{	
	int k = 0;
	char arr[100];
    scanf("%s%d", arr, k);
	left_rotate(arr, k);
	printf("%s\n", arr);
}

/*2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0. 
AABCD左旋一个字符得到ABCDA 
AABCD左旋两个字符得到BCDAA 
AABCD右旋一个字符得到DAABC*/
#include <stdio.h>
#include <assert.h>
#include <string.h>
int is_left_rotate(char* str1, char* str2)
{
	
	int len1 =strlen(str1);
	int len2 =strlen(str2);
	assert(str1 && str2);
	if(len1 != len2)
	{
		return 0;
	}
	strncat(str1, str1, len1);
	if(strstr(str1, str2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char a1[20] = "ABCDD";
	char a2[] = "DDABC";
	int ret = is_left_rotate(a1,a2);
	if(ret == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}

/*2.杨氏矩阵
有一个二维数组,数组的每行从左到右是递增的，每列从上到下是递增的.
在这样的数组中查找一个数字是否存在.时间复杂度小于O(N);
数组：
1 2 3
2 3 4
3 4 5

1 3 4
2 4 5
4 5 6

1 2 3
4 5 6
7 8 9*/
int search(int a[3][3], int row, int col, int k, int* px, int* py)
{
	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0)
	{
		if (a[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if (a[i][j] < k)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}

int main()
{
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int px;
	int py;
	search(a, 3, 3, 5, &px, &py);
	printf("%d %d\n", px, py);
	return 0;
}