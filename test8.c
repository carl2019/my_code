/*1.5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
Aѡ��˵��B�ڶ����ҵ����� 
Bѡ��˵���ҵڶ���E���ģ� 
Cѡ��˵���ҵ�һ��D�ڶ��� 
Dѡ��˵��C����ҵ����� 
Eѡ��˵���ҵ��ģ�A��һ�� 
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�*/
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

/*2.�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
A˵�������ҡ� 
B˵����C�� 
C˵����D�� 
D˵��C�ں�˵ 
��֪3����˵���滰��1����˵���Ǽٻ��� 
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�*/ 
#include <stdio.h>
void killer()
{
    char killer = '0';
	for(killer = 'A'; killer <= 'D'; killer++)
	{
		if((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("�����ǣ�%c\n", killer);
		}
	}
}

int main()
{
	killer();
	return 0;
}

/*3.����Ļ�ϴ�ӡ������ǡ� 
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
	//������ϵ�ֵ
	for(i=0; i<N; i++)
	{
        a[i][0] = 1;
		a[i][i] = 1;
	}
	//��������Ԫ�ص�ֵ
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

//4.1-100���������г��ֶ��ٴ�����9
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