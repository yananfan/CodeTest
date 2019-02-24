//#define PrintListInReversedOrder_
#ifdef PrintListInReversedOrder_

#include<iostream>
#include<stack>
#include"05_List.h"

using namespace std;

void PrintListReversingly_Iteratively(ListNode* pHead); 
void PrintListReversingly_Recursively(ListNode* pHead); 

int main()
{
	ListNode* pNode1 = CreateListNode(1); // 多个节点
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);

	PrintListNode(pNode1);
	PrintListReversingly_Iteratively(pNode1);
	cout << endl;
	PrintListReversingly_Recursively(pNode1);
	cout << endl;
	DestroyListNode(pNode1);

	ListNode* pNode11 = CreateListNode(1); // 一个节点
	PrintListNode(pNode11);
	PrintListReversingly_Iteratively(pNode11);
	cout << endl;
	PrintListReversingly_Recursively(pNode11);
	DestroyListNode(pNode11);

	ListNode* pNode12 = NULL; // 头指针为空
	PrintListNode(pNode12);
	PrintListReversingly_Iteratively(pNode12);
	cout << endl;
	PrintListReversingly_Recursively(pNode12);
	DestroyListNode(pNode12);
}
void PrintListReversingly_Iteratively(ListNode* pHead) {
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()) {
		pNode = nodes.top();
		cout << pNode->m_nValue << " ";
		nodes.pop();
	}
	cout << endl;
}
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != NULL) {
		if (pHead->m_pNext != NULL) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout << pHead->m_nValue << " ";
	}
}
#endif // PrintListInReversedOrder_