#include "SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode = (SListNode*)malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;

	return pnode;
}

void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);

	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		SListNode* tail = plist->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		SListNode* newtail = BuySListNode(x);
		tail->_next = newtail;
	}	
}

void SListPopBack(SList* plist)
{
	assert(plist);
	//只有一个节点
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	//有多个节点
	else
	{
		SListNode* tail = plist->_head;
		SListNode* prev = NULL;
		while (tail->_next != NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newhead = BuySListNode(x);
	newhead->_next = plist->_head;
	plist->_head = newhead;
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}
	return cur;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newnode = BuySListNode(x);

	newnode->_next = next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	pos->_next = pos->_next->_next;
}

void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	
}

void SListTest1()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushBack(&list, 0);
	SListPrint(&list);

	SListPopFront(&list);
	SListPopBack(&list);
	SListPrint(&list);

	SListNode* pos = SListFind(&list, 2);
	SListInsertAfter(pos, 30);
	SListPrint(&list);

	SListDestory(&list);
}
