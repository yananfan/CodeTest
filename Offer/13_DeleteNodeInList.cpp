//#define _DeleteNode_
#ifdef _DeleteNode_

#include<iostream>
#include"05_List.h"

using namespace std;

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);

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

	PrintListNode(pNode1);

	DeleteNode(&pNode1, pNode3);
	PrintListNode(pNode1);

	DeleteNode(&pNode1, pNode5);
	PrintListNode(pNode1);

	DeleteNode(&pNode1, pNode1);
	PrintListNode(pNode1);
	DestroyListNode(pNode1);

	ListNode* pNode6 = CreateListNode(6);
	PrintListNode(pNode6);
	DeleteNode(&pNode6, pNode6);
	PrintListNode(pNode6);

	return 0;
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if (!pListHead || !pToBeDeleted) return;
	// 删除普通节点
	if (pToBeDeleted->m_pNext != NULL) {
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	// 删除头结点
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	// 删除尾节点
	else {
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
#endif // _DeleteNode_