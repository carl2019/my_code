#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	//控制end的值将[end +1]插入到有序区间[0,end]
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		//单趟排序
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
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

void TestShellSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int*p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
				max = i;

			if (a[i] < a[min])
				min = i;
		}

		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}

		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
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
	else //a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);
	int key = begin;
	while (begin < end)
	{
		//end找小
		while (begin < end && a[end] >= a[key])
			--end;

		//begin找大
		while (begin < end && a[begin] <= a[key])
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[end]);
	return end;
}

int PartSort2(int*a, int begin, int end)
{
	int tmp = a[begin];
	while (begin < end)
	{
		//找小，填到左边的坑
		while (begin < end && a[end] >= tmp) //必须有等于，否则可能会陷入死循环
			--end;

		a[begin] = a[end];
		//找大，填到右边的坑
		while (begin < end && a[begin] <= tmp)
			++begin;

		a[end] = a[begin];
	}

	a[begin] = tmp;
}

int PartSort3(int*a, int begin, int end)
{
	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
		return;

	//[left, div-1] [div+1, right]
	int div = PartSort3(a, left, right);
	QuickSort1(a, left, div - 1);
	QuickSort1(a, div + 1, right);
}

void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;

	//[left, div-1] [div+1, right]
	if (right - left > 10)
	{
		int div = PartSort3(a, left, right);
		QuickSort2(a, left, div - 1);
		QuickSort2(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

void TestQuickSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = begin + ((end - begin) >> 1);

	//子问题 对[begin, mid] [mid + 1， end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	//归并[begin, mid-1] [mid, end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	//归并结果拷回原数组
	index = begin;
	while (begin <= end)
		a[begin++] = tmp[index++];
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void CountSort(int* a, int n)
{
	//计算范围
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//统计数据个数
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int)* range);
	memset(count, 0, sizeof(int)* range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 9, 2, 1, 5, 4, 7, 6, 9, 7 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}



