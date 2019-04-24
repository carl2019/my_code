#pragma once
#include "common.h"

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* _array;
	size_t _capacity;
	size_t _size;
}SeqList;

void SeqListInit(SeqList* ps, size_t capacity);
void SeqListDestory(SeqList* ps);
void SeqListPrint(SeqList* ps);

void CheckCapacity(SeqList* ps);

void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopFront(SeqList* ps);

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);
void SeqListErase(SeqList* ps, size_t pos);
int SeqListFind(SeqList* ps, SLDataType x);
size_t SeqListSize(SeqList* ps);
int SeqListEmpty(SeqList* ps);
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);

void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, SLDataType x);
void SeqListRemoveAll(SeqList* ps, SLDataType x);

void SeqListTest1();
void SeqListTest2();
void SeqListTest3();
void SeqListTest4();
