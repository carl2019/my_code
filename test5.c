//1.һ��������ֻ�����������ǳ���һ�Σ� 
//�����������ֶ�����������.�ҳ����������֣����ʵ�֡� 
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,1,2,3,4,5,6};
	int sz = sizeof(arr)/sizeof(arr[0]);
	//���浥�����ֵ�Ԫ�������
	int ret = 0;
	//�������������1��λ��
    int pos = 0;
	//���浥�����ֵ�Ԫ�ص�ֵ
	int x = 0;
	int y = 0;
	int i;
    //������Ԫ�ص������
	for(i = 0; i < sz; i++)
	{
		ret ^=arr[i];
	}
	//�ҳ����������1��λ��
	for(i = 0; i < 32; i++)
	{
        if(((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//����posλΪ1����0�ķ���
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

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
//��20Ԫ�����Զ�����ˮ�����ʵ�֡�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	printf("������һ������");
	scanf("%d", &money);
	total = money;
	empty = money;
	while(empty > 1)
	{
		total += empty/2;
		empty = empty/2 +empty%2;
	}
	printf("���Ժ� %d ƿ��ˮ\n", total);
}

//3.ʵ��strstr
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
		printf("�Ҳ���\n");
	}
	return 0;
}

//4.ʵ��strchr 
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