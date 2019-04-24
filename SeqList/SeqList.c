# include "SeqList.h"

void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);
	ps->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	ps->_capacity = capacity;
	ps->_size = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_size = 0;
	}
}

void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_array = realloc(ps->_array, ps->_capacity*sizeof(SLDataType));
		assert(ps->_array);
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	/*assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;*/
	SeqListInsert(ps, ps->_size, x);
}

void SeqListPopBack(SeqList* ps)
{
	/*assert(ps && ps->_size > 0);
	ps->_size--;*/
	SeqListErase(ps, ps->_size - 1);
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	/*assert(ps);
	CheckCapacity(ps);

	int end = ps->_size - 1;
	while (end >= 0)
	{
		ps->_array[end + 1] = ps->_array[end];
		end--;
	}
	ps->_array[0] = x;
	ps->_size++;*/
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList*ps)
{
	/*assert(ps);
	int begin = 0;
	while (begin < ps->_size - 1)
	{
		ps->_array[begin] = ps->_array[begin + 1];
		begin++;
	}
	ps->_size--;*/
	SeqListErase(ps, 0);
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos <= ps->_size);
	CheckCapacity(ps);

	/*int end = ps->_size - 1;
	while ((int)pos <= end)
	{
		ps->_array[end + 1] = ps->_array[end];
		end--;
	}*/
	size_t end = ps->_size;
	while (end > pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}

	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	while (pos < ps->_size - 1)
	{
		ps->_array[pos] = ps->_array[pos+1];
		pos++;
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
			return i;
	}
	return -1;
}

size_t SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;
}

int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->_size > 0 ? 1 : 0;
}

void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos < ps->_size);
	ps->_array[pos] = x;
}

void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	size_t finish = ps->_size;
	while (finish > 1)
	{
		for (size_t i = 1; i < finish; ++i)
		{
			if (ps->_array[i] < ps->_array[i - 1])
			{
				SLDataType tmp = ps->_array[i];
				ps->_array[i] = ps->_array[i - 1];
				ps->_array[i - 1] = tmp;
			}
		}
		--finish;
	}
}

int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int begin = 0, end = ps->_size;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (ps->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else if (ps->_array[mid] > x)
		{
			end = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, SLDataType x)
{
	size_t cur = 0;
	size_t dst = 0;
	while (cur < ps->_size)
	{
		if (ps->_array[cur] != x)
		{
			ps->_array[dst] = ps->_array[cur];
			++dst;
		}
		++cur;
	}
	ps->_size = dst;
}

void SeqListPrint(SeqList* ps)
{
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListTest1()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);
}

void SeqListTest2()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);

	/*SeqListPopBack(&s);
	SeqListPopFront(&s, 0);
	SeqListPrint(&s);*/

	SeqListInsert(&s, 1, 20);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);

	SeqListFind(&s, 2);
	SeqListPrint(&s);

	SeqListDestory(&s);
}

void SeqListTest3()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 0);

	SeqListPrint(&s);

	SeqListBubbleSort(&s);
	SeqListPrint(&s);

	printf("find index:%d\n", SeqListBinaryFind(&s, 0));
	printf("find index:%d\n", SeqListBinaryFind(&s, 1));
	printf("find index:%d\n", SeqListBinaryFind(&s, 2));
	printf("find index:%d\n", SeqListBinaryFind(&s, 3));
	printf("find index:%d\n", SeqListBinaryFind(&s, 4));
	printf("find index:%d\n", SeqListBinaryFind(&s, 5));
	printf("find index:%d\n", SeqListBinaryFind(&s, 6));
	printf("find index:%d\n", SeqListBinaryFind(&s, 7));
	printf("find index:%d\n", SeqListBinaryFind(&s, 8));
	printf("find index:%d\n", SeqListBinaryFind(&s, 9));
	printf("find index:%d\n", SeqListBinaryFind(&s, 10));

	SeqListDestory(&s);
}

void SeqListTest4()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPrint(&s);

	SeqListRemoveAll(&s, 2);
	SeqListPrint(&s);

	SeqListDestory(&s);
}