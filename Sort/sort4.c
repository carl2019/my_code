#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
			--end;
		while (begin < end && a[begin] <= a[key])
			++begin;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	return begin;
}

void QuickSort(int*a, int left, int right)
{

	if (left >= right)
		return;
	/*if (right - left > 10)
	{*/
	int div = PartSort1(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
	/*}
	else
	{InsertSort(a + left, right -left + 1);
	}*/
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[end] < a[mid])
			return mid;
		else if (a[end] > a[begin])
			return begin;
		else
			return end;
	}
}

int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = a[begin];
	while (begin < end)
	{
		while (begin<end && a[end] > key)
		{
			--end;
			a[begin] = a[end];
		}
		while (begin < end && a[begin] < key)
		{
			++begin;
			a[end] = a[begin];
		}
	}
	a[begin] = key;
	return begin;
}

void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left > 10)
	{
		int div = PartSort2(a, left, right);
		QuickSort2(a, left, div - 1);
		QuickSort2(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int cur = begin + 1;
	int prev = begin;
	int key = a[begin];
	while (cur <= end)
	{
		if (a[cur] < key)
		{
			Swap(&a[prev++], &a[cur]);
			cur++;
		}
	}
	Swap(&a[prev], &key);
	return prev;
}

void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left > 10)
	{
		int div = PartSort3(a, left, right);
		QuickSort3(a, left, div - 1);
		QuickSort3(a, div + 1, right);
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
	
	QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	SortPrint(a, sizeof(a) / sizeof(int));

	QuickSort2(a, 0, (sizeof(a) / sizeof(int)) - 1);
	SortPrint(a, sizeof(a) / sizeof(int));

	QuickSort3(a, 0, (sizeof(a) / sizeof(int)) - 1);
	SortPrint(a, sizeof(a) / sizeof(int));

}