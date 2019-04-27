//1.完成猜数字游戏。
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
		printf("请输入猜的数字\n");
		scanf("%d", &num);
		if(num == set)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if(num > set)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
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
		printf("请选择:>");
        scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}while(input);
	return 0;
}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找） 
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
		printf("找到了，下标是%d\n");
	}
	else
	{
		return -1;
	}
	return 0;
}

/*3.编写代码模拟三次密码输入的场景。 
最多能输入三次密码，密码正确，提示“登录成功”,密码错误，可以重新输入，最多输入三次。
三次均错，则提示退出程序。*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    char password[20] = {0};
    for(i=0; i<3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if(0 == strcmp(password, "123456"))
		{
			break;
		}
		else
		{
			printf("密码输入错误，请再次输入！\n");		
		}
	}
	if(i<3)
		printf("登录成功\n");
	else
		printf("退出程序\n");		
    return 0;
}

/*4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，
如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。*/ 
#include <stdio.h>
int main()
{
	int input;
	while((input = getchar()) != EOF )
	{
		//判断是不是大写字符
		if(input >= 'A' && input <= 'Z')
		{
			putchar(input + 32);
			putchar('\n');
		}
		//判断是不是小写字符
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