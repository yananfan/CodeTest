#pragma once
#include<iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
// 创建一个节点
ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;

	return pNode;
}
// 链接节点
void ConnectListNode(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode1 == NULL) return;
	pNode1->m_pNext = pNode2;
}
//遍历链表   
void PrintListNode(ListNode* pHead)
{
	if (pHead == NULL) return;
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}
//销毁链表  
void DestroyListNode(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		pNode = pNode->m_pNext;
		delete pHead;
		pHead = pNode;
	}
}
// 在尾部添加节点
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}
// 删除指定值的节点
void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL) return;
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL&&pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if (pNode->m_pNext != NULL&&pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != NULL) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
