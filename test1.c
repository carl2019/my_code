//1.��ɲ�������Ϸ��
#include <stdio.h>
#include <time.h>
void menu()
{
	printf("********************\n");
	printf("***** 1. play  *****\n");
	printf("***** 0. exit  *****\n");
	printf("********************\n");

}
void game()
{
	int num = 0;
	int set = rand()%100+1;
	while(1)
	{
		printf("������µ�����\n");
		scanf("%d", &num);
		if(num == set)
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		else if(num > set)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
        menu();
		printf("��ѡ��:>");
        scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}while(input);
	return 0;
}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң� 
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int key = 0;
    int left = 0;
	int right = sizeof(arr)/sizeof(arr[0])-1;
	int mid = 0;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid] < key)
		{
		    left = mid + 1;
	    }
	    else if(arr[mid] < key)
	    {
	    	right = mid - 1;
	    }
		else
		{
			break;
		}
	}
	if(left <= right)
	{
		printf("�ҵ��ˣ��±���%d\n");
	}
	else
	{
		return -1;
	}
	return 0;
}

/*3.��д����ģ��������������ĳ����� 
����������������룬������ȷ����ʾ����¼�ɹ���,������󣬿����������룬����������Ρ�
���ξ�������ʾ�˳�����*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    char password[20] = {0};
    for(i=0; i<3; i++)
	{
		printf("����������:>");
		scanf("%s", password);
		if(0 == strcmp(password, "123456"))
		{
			break;
		}
		else
		{
			printf("��������������ٴ����룡\n");		
		}
	}
	if(i<3)
		printf("��¼�ɹ�\n");
	else
		printf("�˳�����\n");		
    return 0;
}

/*4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���
������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������*/ 
#include <stdio.h>
int main()
{
	int input;
	while((input = getchar()) != EOF )
	{
		//�ж��ǲ��Ǵ�д�ַ�
		if(input >= 'A' && input <= 'Z')
		{
			putchar(input + 32);
			putchar('\n');
		}
		//�ж��ǲ���Сд�ַ�
		else if(input >= 'a' && input <= 'z')
		{
			putchar(input - 32);
			putchar('\n');
		}
		else if(input >= '0' && input <= '9')
		{
		}
	}
	return 0;
}