//#define _17_MergeSortedLists_
#ifdef _17_MergeSortedLists_

#include<iostream>
#include"05_List.h"

using namespace std;

ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
int main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNode(pNode1, pNode3);
	ConnectListNode(pNode3, pNode5);
	ConnectListNode(pNode5, pNode7);
	cout << "第一个链表：" << endl;
	PrintListNode(pNode1);

	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode8 = CreateListNode(8);

	ConnectListNode(pNode2, pNode4);
	ConnectListNode(pNode4, pNode6);
	ConnectListNode(pNode6, pNode8);
	cout << "第二个链表：" << endl;
	PrintListNode(pNode2);

	ListNode* pNew = Merge(pNode1, pNode2);
	cout << "合并后的链表：" << endl;
	PrintListNode(pNew);

	return 0;
}
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead2;
	ListNode* pNewHead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue) {
		pNewHead = pHead1;
		pNewHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else {
		pNewHead = pHead2;
		pNewHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pNewHead;
}
#endif // _17_MergeSortedLists_