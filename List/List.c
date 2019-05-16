#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_prev = NULL;
	node->_next = NULL;
	node->_data = x;
	
	return node;
}

void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(-1);
	head->_next = head;
	head->_prev = head;

	plist->_head = head;
}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPrint(List* plist)
{
	assert(plist);
	printf("<-head->");
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListPushBack(List* plist, LTDataType x)
{
	/*assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newtail = BuyListNode(x);

	tail->_next = newtail;
	newtail->_prev = tail;
	newtail->_next = head;
	head->_prev = newtail;*/

	ListInsert(plist->_head, x);
}

void ListPopBack(List* plist)
{
	/*assert(plist && plist->_head != plist->_head->_next);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* tailprev = tail->_prev;
	
	free(tail);
	head->_prev = tailprev;
	tailprev->_next = head;*/

	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)
{
	/*assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyListNode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;*/

	ListInsert(plist->_head->_next, x);
}

void ListPopFront(List* plist)
{
	/*assert(plist && plist->_head != plist->_head->_next);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* next = cur->_next;
	
	free(cur);
	head->_next = next;
	next->_prev = head;*/

	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//在pos的前面插入节点
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

//删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListRemove(List* plist, LTDataType x)
{
	assert(plist);

	ListNode* node = ListFind(plist, x);
	if (node)
	{
		ListErase(node);
	}
}

int ListSize(List* plist)
{
	assert(plist);
	int size = 0;

	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

//空返回0 非空返回-1
int ListEmpty(List* plist)
{
	assert(plist);
	return plist->_head->_next == plist->_head ? 0 : -1;
}

void ListTest1()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPopBack(&list);
	ListPushFront(&list,0);
	ListPopFront(&list);

	ListPrint(&list);
	printf("%d\n", ListSize(&list));
	printf("%d\n", ListEmpty(&list));



	ListDestory(&list);
}