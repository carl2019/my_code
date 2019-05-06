#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int my_strlen(const char* arr)
{
	int count = 0;
	assert(arr != NULL);
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}

//#长度不受限制的字符串函数:strcpy strcat strcmp

//1.实现strcpy
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//2.实现strcat 
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//找到目标空间的第一个'\0'
	while (*dest)
	{
		dest++;
	}
	//拷贝
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//3.实现strcmp 
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int test1()
{
	int ret = my_strcmp("abcde", "abcde");
	printf("%d\n", ret);
	return 0;
}

//#长度受限制的字符串函数:strncpy strncat strncmp

//拷贝num个字符从源字符串到目标空间
//如果源字符串小于num，拷完源字符串之后，在目标之后加0，直到num个
char* my_strncpy(char* dest, const char* src, int count)
{
	char* ret = dest;

	assert(dest != NULL);
	assert(src != NULL);
	while (count && (*dest++ = *src++))
	{
		count--;
	}
	if (count)
	{
		while (--count)
		{
			*dest = '\0';
			dest++;
		}
	}
	return ret;
}

//追加一个字符串要在后面加'\0' ，追加之后还是字符串
//追加的字符串不够，遇到'\0'就结束
char* my_strncat(char* dest, const char* src, int count)
{
	char* ret = dest;

	assert(dest != NULL);
	assert(src != NULL);

	while (*dest)
	{
		dest++;
	}
	while (count && (*src))
	{
		*dest++ = *src++;
		count--;
	}
	*dest = '\0';
	return ret;
}

int my_strncmp(const char*str1, const char*str2, int count)
{
	assert(str1 != NULL);
	assert(str1 != NULL);
	while (--count && *str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

void test2()
{
	char arr[20] = "hello";
	my_strncat(arr, "world", 7);
	printf("%s\n", arr);
}

int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}
