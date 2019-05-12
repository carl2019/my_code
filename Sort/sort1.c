#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void InsertSort(int* a, int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void SortTest()
{
	int a[] = { 1, 8, 9, 7, 4, 5, 2, 3, 6, 0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));
}