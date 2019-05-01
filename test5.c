//1.一个数组中只有两个数字是出现一次， 
//其他所有数字都出现了两次.找出这两个数字，编程实现。 
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,1,2,3,4,5,6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	//保存单处出现的元素异或结果
	int ret = 0;
	//保存异或结果出现1的位置
    int pos = 0;
	//保存单独出现的元素的值
	int x = 0;
	int y = 0;
	int i;
    //求所有元素的异或结果
	for(i = 0; i < sz; i++)
	{
		ret ^=arr[i];
	}
	//找出异或结果出现1的位置
	for(i = 0; i < 32; i++)
	{
        if(((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//按照pos位为1或者0的分组
    for(i = 0; i < sz; i++)
	{
        if(((arr[i] >> pos) & 1) == 1)
		{
			x ^=arr[i];
		}
		else
		{
			y ^=arr[i];
		}
	}
	printf("%d %d\n", x, y);
	return 0;	
}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//给20元，可以多少汽水。编程实现。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	printf("请输入一个数：");
	scanf("%d", &money);
	total = money;
	empty = money;
	while(empty > 1)
	{
		total += empty/2;
		empty = empty/2 +empty%2;
	}
	printf("可以喝 %d 瓶汽水\n", total);
}

//3.实现strstr
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* src, const char* dest)
{
    
	const char* s1 = src;
    const char* s2 = dest;
	const char* cur = src;
	assert(src&&dest);
	while(*cur)
	{
		s1 = cur;
		s2 = dest;
		while(*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return (char*) cur;
		}
		if(*s1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;
}

int main()
{
	char* p = "abbbcdef";
	char* q = "bbe";
	char* ret = my_strstr(p,q);
	if(ret != NULL)
	{
		printf("%s\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}

//4.实现strchr 
#include <stdio.h>
#include <assert.h>
char* my_strchr(const char* str, char c)
{
	assert(str != NULL);
	while(*str != '\0')
	{
		if(*str == c)
		{
			return(char*) str;
		}
		str++;
	}
	return NULL;
}

int main()
{
    char* p = "abbbcdef";
	printf("%s\n", my_strchr(p, 'c'));
	return 0;
}