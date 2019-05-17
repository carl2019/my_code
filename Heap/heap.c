#include "heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(HPDataType* a, size_t n, int root)
{

	size_t parent = root;
	size_t child = parent * 2 + 1;

	while (child < n)
	{
		//找左右孩子小的
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);

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

void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void AdjustUp(HPDataType* a,size_t n, size_t child)
{
	assert(a);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity*sizeof(HPDataType));
		assert(hp->_array);
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	//调堆
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_array, hp->_size, 0);
}

size_t HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

void TopK()
{
	const size_t N = 10000;
	const size_t K = 100;
	size_t* a = (size_t*)malloc(sizeof(size_t)*N);
	for (size_t i = 0; i < N; ++i)
	{
		a[i] = rand()%100000;
	}

	a[2] = 100001;
	a[19] = 100002;
	a[23] = 100003;
	a[34] = 100004;
	a[78] = 100005;

	Heap hp;
	HeapInit(&hp, a, K);
	for (size_t i = K; i < N; ++i)
	{
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}

//升序->大堆 
void HeapSort(int* a, size_t n)
{
	assert(a);
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	size_t end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void HeapTest1()
{
	int a[10] = { 11, 14, 9, 23, 34, 16, 24, 65, 52, 45 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	HeapPush(&hp, 70);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(a, sizeof(a) / sizeof(int));
	for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
 