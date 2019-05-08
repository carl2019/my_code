#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;

//typdef struct Heap Heap

void HeapInit(Heap* hp, HPDataType* a, size_t n);
void HeapDestory(Heap* hp);
void HeapPrint();

void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

// ∂—≈≈–Ú
void HeapSort(int* a, int n);
void HeapTest1();
