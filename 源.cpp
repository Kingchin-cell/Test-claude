#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 定义链表节点的数据类型
typedef int SLTDataType;

// 单链表节点结构体
typedef struct SListNode
{
	SLTDataType data;        // 数据域
	struct SListNode* next;  // 指针域，指向下一个节点
}SLTNode;

// 打印链表
void SLTPrint(SLTNode* phead)
{
	assert(phead != NULL);
	SLTNode* pCur = phead;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

// 创建一个固定链表：12 -> 23 -> 34 -> 45
SLTNode* createList()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 12;
	node2->data = 23;
	node3->data = 34;
	node4->data = 45;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	return node1;
}

// 申请一个新节点，并初始化
SLTNode* buyNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->next = NULL;
	return node;
}

// 头插：在链表头部插入新节点
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead != NULL);
	SLTNode* node = buyNode(x);
	node->next = *pphead;
	*pphead = node;
}

// 头删：删除链表第一个节点
void SLTHeadDelete(SLTNode** pphead)
{
	assert(pphead != NULL);
	assert(*pphead != NULL);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// 尾插：在链表尾部插入新节点
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead != NULL);
	SLTNode* node = buyNode(x);
	if (*pphead == NULL)
	{
		*pphead = node;
	}
	else
	{
		SLTNode* Cur = *pphead;
		while (Cur->next != NULL)
		{
			Cur = Cur->next;
		}
		Cur->next = node;
	}
}

// 尾删方式1：用两个指针遍历，prev 指向 ptail 的前一个节点
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = NULL;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

// 尾删方式2：用 Cur->next->next 判断是否到倒数第二个节点
void SLTPopBack2(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* Cur = *pphead;
		while ((Cur->next)->next != NULL)
		{
			Cur = Cur->next;
		}
		free(Cur->next);
		Cur->next = NULL;
	}
}

// 按值查找节点，返回节点指针
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead != NULL);
	while (phead != NULL)
	{
		if (phead->data == x)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}

// 获取链表长度
int Getlen(SLTNode* phead)
{
	int count = 0;
	while (phead != NULL)
	{
		count++;
		phead = phead->next;
	}
	return count;
}

// 找到指定位置 pos 的前一个节点
SLTNode* Find_Previous(SLTNode* phead, int pos)
{
	int count = 0;
	while (count != pos - 1)
	{
		phead = phead->next;
		count++;
	}
	return phead;
}

// 在指定位置 n 处插入值为 x 的新节点
void SLTInsert(SLTNode** pphead, int n, SLTDataType x)
{
	assert(pphead != NULL);
	int len = Getlen(*pphead);
	assert(n >= 0 && n <= len);
	if (n == 0)
	{
		SLTPushFront(pphead, x);
		return;
	}
	if (n == len)
	{
		SLTPushBack(pphead, x);
		return;
	}
	SLTNode* prev = Find_Previous(*pphead, n);
	SLTNode* node = buyNode(x);
	node->next = prev->next;
	prev->next = node;
}

// 找到值为 key 的节点的前一个节点
SLTNode* findPrevOfKey(SLTNode* phead, int key)
{
	SLTNode* prev = phead;
	while (prev->next != NULL)
	{
		if (prev->next->data == key)
		{
			return prev;
		}
		prev = prev->next;
	}
	return NULL;
}

// 按关键字 key 删除节点
void SLTErase(SLTNode** pphead, int key)
{
	assert(pphead != NULL);
	assert(*pphead != NULL);
	// 如果要删除的是头节点
	if ((*pphead)->data == key)
	{
		SLTNode* pCur = *pphead;
		*pphead = (*pphead)->next;
		free(pCur);
	}
	//-------//
	SLTNode* prev = findPrevOfKey(*pphead, key);
	if (prev == NULL)
	{
		printf("没有要找到的关键字");
		return;
	}
	else
	{
		SLTNode* pdel = prev->next;
		prev->next = pdel->next;
		free(pdel);
		pdel = NULL;
	}
}

// 销毁整个链表，释放所有节点内存
void SLTDelete(SLTNode** pphead)
{
	assert(pphead != NULL);
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

// 测试
int main()
{
	SLTNode* plist = createList();
	SLTPrint(plist);

	SLTDelete(&plist);
	SLTPrint(plist);

	return 0;
}
