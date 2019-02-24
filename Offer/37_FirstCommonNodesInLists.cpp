//#define _FirstCommonNodesInLists_
#ifdef _FirstCommonNodesInLists_

#include<iostream>
#include"05_List.h"
using namespace std;

int GetListLength(ListNode* pHead);
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2);
int main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	// 第一个公共结点在链表中间
	// 1 - 2 - 3 \
	//            6 - 7
    //     4 - 5 /
	/*ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode6);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintListNode(pNode1);
	PrintListNode(pNode4);

	ListNode* pResult = FindFirstCommonNode(pNode1, pNode4);*/

	// 没有公共结点
	// 1 - 2 - 3 - 4
	//            
	// 5 - 6 - 7
	/*ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintListNode(pNode1);
	PrintListNode(pNode5);

	ListNode* pResult = FindFirstCommonNode(pNode1, pNode5);*/

	// 公共结点是最后一个结点
	// 1 - 2 - 3 - 4 \
	//                7
    //         5 - 6 /
	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode7);
	ConnectListNode(pNode5, pNode6);
	ConnectListNode(pNode6, pNode7);

	PrintListNode(pNode1);
	PrintListNode(pNode5);

	ListNode* pResult = FindFirstCommonNode(pNode1, pNode5);

	return 0;
}
int GetListLength(ListNode* pHead) {
	int length = 0;
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		++length;
		pNode = pNode->m_pNext;
	}
	return length;
}
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
	int len1 = GetListLength(pHead1);
	int len2 = GetListLength(pHead2);
	int lendiff = len1 - len2;
	ListNode* pLong = pHead1;
	ListNode* pShort = pHead2;
	if (len1 < len2) {
		pLong = pHead2;
		pShort = pHead1;
		lendiff = len2 - len1;
	}
	for (int i = 0;i < lendiff;i++)
		pLong = pLong->m_pNext;
	while (pLong != NULL && pShort != NULL && pLong != pShort) {
		pLong = pLong->m_pNext;
		pShort = pShort->m_pNext;
	}
	ListNode* pFirstCommon = pLong;
	if (pFirstCommon == NULL)
		cout << "没有公共节点。" << endl;
	else
		cout << "第一个公共节点是： " << pFirstCommon->m_nValue << endl;
	return pFirstCommon;
}
#endif // _FirstCommonNodesInLists_