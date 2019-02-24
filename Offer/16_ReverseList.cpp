//#define _16_ReverseList_
#ifdef _16_ReverseList_

#include<iostream>
#include"05_List.h"

using namespace std;

// 用3个指针
ListNode* ReverseList_1(ListNode* pHead);
// 依次插入头结点之后，最后再调整头结点
ListNode* ReverseList_2(ListNode* pHead);
// 递归实现
ListNode* ReverseList_3(ListNode* pHead);
int main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);

	cout << "原始链表是：  ";
	PrintListNode(pNode1);

	cout << "反转链表（3个指针）是：  ";
	ListNode* pNew = ReverseList_1(pNode1);
	PrintListNode(pNew);

	cout << "反转链表（头插法）是：  ";
	ListNode* pNew_2 = ReverseList_2(pNew);
	PrintListNode(pNew_2);

	cout << "反转链表（递归法）是：  ";
	ListNode* pNew_3 = ReverseList_2(pNew_2);
	PrintListNode(pNew_3);
	return 0;
}
ListNode* ReverseList_1(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	ListNode* pPre = NULL;
	ListNode* pNode = pHead;
	ListNode* pNewHead = NULL;
	while (pNode != NULL) {
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
			pNewHead = pNode;
		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = pNext;
	}
	return pNewHead;
}
ListNode* ReverseList_2(ListNode* pHead) {
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;
	else {
		ListNode* pNode = pHead->m_pNext;
		ListNode* qNode;
		while (pNode->m_pNext != NULL) {
			qNode = pNode->m_pNext;
			pNode->m_pNext = qNode->m_pNext;
			qNode->m_pNext = pHead->m_pNext;
			pHead->m_pNext = qNode;
		}
		pNode->m_pNext = pHead;
		pHead = pNode->m_pNext->m_pNext;
		pNode->m_pNext->m_pNext = NULL;

		return pHead;
	}
}
ListNode* ReverseList_3(ListNode* pHead) {
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;
	else {
		ListNode* pNewHead = ReverseList_3(pHead->m_pNext);
		pHead->m_pNext->m_pNext = pHead;
		pHead->m_pNext = NULL;
		return pNewHead;
	}
}
#endif // _16_ReverseList_