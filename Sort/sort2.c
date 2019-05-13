#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//在左右孩子选择大的
		if (child + 1 < n &&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapSort(int* a, int n)
{
	//建大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//选数
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i <= end; i++)
		{

			if (a[i]<a[min])
			{
				min = i;
			}
			if (a[i]>a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0; i < end - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				exchange = 1;
			}
		}
		end--;
	}
}

void SortPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void SortTest()
{
	int a[] = { 1, 8, 9, 7, 4, 5, 2, 3, 6, 0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	SortPrint(a, sizeof(a) / sizeof(int));
}