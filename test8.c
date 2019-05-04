/*1.5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
A选手说：B第二，我第三； 
B选手说：我第二，E第四； 
C选手说：我第一，D第二； 
D选手说：C最后，我第三； 
E选手说：我第四，A第一； 
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。*/
#include <stdio.h>
int main()
{
	int a, b, c, d, e;
	for(a = 1; a <= 5; a++)
	{
		for(b = 1; b <= 5; b++)
		{
			for(c = 1; c <= 5; c++)
			{
				for(d = 1; d <= 5; d++)
				{
					for(e = 1; e <= 5; e++)
					{
						if(((b == 2 && a != 3)||(b != 2 && a == 3))
							&&((b == 2 && e != 2)||(b != 2 && e == 2))
							&&((c == 1 && d != 2)||(c != 1 && d == 2))
							&&((c == 5 && d != 3)||(c != 5 && d == 3))
							&&((e == 5 && a != 1)||(e != 5 && a == 1)))
						{
							if((a*b*c*d*e == 120) && (a+b+c+d+e == 15))
							printf("a=%d b=%d c=%d d=%d e=%d\n" ,a,b,c,d,e);
						}
					}
				}
			}
		}
	}
	return 0;
}

/*2.日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
嫌疑犯的一个。以下为4个嫌疑犯的供词。 
A说：不是我。 
B说：是C。 
C说：是D。 
D说：C在胡说 
已知3个人说了真话，1个人说的是假话。 
现在请根据这些信息，写一个程序来确定到底谁是凶手。*/ 
#include <stdio.h>
void killer()
{
    char killer = '0';
	for(killer = 'A'; killer <= 'D'; killer++)
	{
		if((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("凶手是：%c\n", killer);
		}
	}
}

int main()
{
	killer();
	return 0;
}

/*3.在屏幕上打印杨辉三角。 
 1 
 1 1 
 1 2 1 
 1 3 3 1 */
#include <stdio.h>
#define N 10
int main()
{
	int a[N][N] = { 0 };
	int i, j;
	//计算边上的值
	for(i=0; i<N; i++)
	{
        a[i][0] = 1;
		a[i][i] = 1;
	}
	//计算其他元素的值
	for(i=2; i<N; i++)
	{
        for(j=1; j<i; j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	for(i=0; i<N; i++)
	{
        for(j=0; j<=i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//4.1-100所有整数中出现多少次数字9
#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for(i = 1; i <= 100; i++)
	{
		if(i%10 == 9)
			count++;
		if(i/10 == 9)
			count++;
	}
	printf("%d\n",count);
	return 0;
}