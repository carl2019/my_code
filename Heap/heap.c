#include "heap.h"

void AdjustDown(HPDataType* a, size_t n, int root)
{

	size_t parent = root;
	size_t child = parent * 2 + 1;

	while (child < n)
	{
		//找左右孩纸小的
		if (child + 1 < n && a[child] > a[child + 1])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);//把a的数据拷过来

	//建堆
	for (int i = (hp->_size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPrint(Heap* hp, size_t n)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void AdjustUp(Heap* hp)
{
	size_t child = hp->_size-1;
	size_t parent = (child - 1) / 2;
	while (child > 1)
	{
		if (hp->_array[child] > hp->_array[parent])
		{
			HPDataType tmp = hp->_array[parent];
			hp->_array[parent] = hp->_array[child];
			hp->_array[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	hp->_array[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_array);
}

void HeapTest1()
{
	int a[10] = { 5, 14, 9, 23, 34, 16, 24, 65, 52, 45 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	HeapPrint(&hp, sizeof(a) / sizeof(int));
	HeapPush(&hp, 11);
	HeapPrint(&hp, sizeof(a) / sizeof(int));
}
 