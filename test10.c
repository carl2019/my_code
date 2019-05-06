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

//#���Ȳ������Ƶ��ַ�������:strcpy strcat strcmp

//1.ʵ��strcpy
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

//2.ʵ��strcat 
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	//�ҵ�Ŀ��ռ�ĵ�һ��'\0'
	while (*dest)
	{
		dest++;
	}
	//����
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//3.ʵ��strcmp 
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

//#���������Ƶ��ַ�������:strncpy strncat strncmp

//����num���ַ���Դ�ַ�����Ŀ��ռ�
//���Դ�ַ���С��num������Դ�ַ���֮����Ŀ��֮���0��ֱ��num��
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

//׷��һ���ַ���Ҫ�ں����'\0' ��׷��֮�����ַ���
//׷�ӵ��ַ�������������'\0'�ͽ���
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
