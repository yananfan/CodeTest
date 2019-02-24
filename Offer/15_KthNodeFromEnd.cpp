//#define _KthNodeFromEnd_
#ifdef _KthNodeFromEnd_

#include<iostream>
#include"05_List.h"
using namespace std;

// 寻找倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead, int k);
// 求链表的中间节点
ListNode* FindMid(ListNode* pListHead);
// 判断是否有环
bool IsLoop(ListNode* pListHead);

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

	ListNode* pNodek = FindKthToTail(pNode1, 2);
	ListNode* pNodem = FindMid(pNode1);
	DestroyListNode(pNode1);

	pNodek = FindKthToTail(NULL, 100);
	pNodem = FindMid(NULL);

	//ConnectListNode(pNode5, pNode3);
	ConnectListNode(pNode1, pNode1);
	bool hasloop = IsLoop(pNode1);
	cout << hasloop << endl;

	return 0;
}

ListNode* FindKthToTail(ListNode* pListHead, int k) {
	if (pListHead == NULL || k == 0) {
		cout << "链表为空或k=0" << endl;
		return NULL;
	}
	ListNode* p1 = pListHead;
	ListNode* p2 = NULL;
	for (int i = 0;i < k - 1;i++) {
		if (p1->m_pNext != NULL)
			p1 = p1->m_pNext;
		else {
			cout << "链表的节点总数小于" << k << endl;
			return NULL;
		}
	}
	p2 = pListHead;
	while (p1->m_pNext != NULL) {
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	cout << "倒数第" << k << "个节点的值为" << p2->m_nValue << endl;
	return p2;
}
ListNode* FindMid(ListNode* pListHead) {
	if (pListHead == NULL) {
		cout << "链表为空" << endl;
		return NULL;
	}
	if (pListHead->m_pNext == NULL || pListHead->m_pNext->m_pNext == NULL) {
		cout << "链表的中间节点是" << pListHead->m_nValue << endl;
		return pListHead;
	}
	ListNode* pfast = pListHead;
	ListNode* pslow = pListHead;
	while (pfast->m_pNext != NULL && pfast->m_pNext->m_pNext != NULL) {
		pslow = pslow->m_pNext;
		pfast = pfast->m_pNext->m_pNext;
	}
	cout << "链表的中间节点是" << pslow->m_nValue << endl;
	return pslow;
}
bool IsLoop(ListNode* pListHead) {
	bool hasloop = false;
	if (pListHead == NULL) {
		cout << "链表为空（无环）" << endl;
		return hasloop;
	}
	ListNode* pfast = pListHead;
	ListNode* pslow = pListHead;
	while (pfast != NULL && pfast->m_pNext != NULL) {
		pslow = pslow->m_pNext;
		pfast = pfast->m_pNext->m_pNext;
		if (pslow == pfast) {
			hasloop = true;
			break;
		}
	}
	if (hasloop)
		cout << "链表有环" << endl;
	else
		cout << "链表没有环" << endl;
	return hasloop;
}
#endif // _KthNodeFromEnd_