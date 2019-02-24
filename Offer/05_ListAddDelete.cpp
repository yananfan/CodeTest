//#define ListAddDelete
#ifdef ListAddDelete

#include<iostream>
#include"05_List.h"

using namespace std;

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

	RemoveNode(&pNode1, 1);
	RemoveNode(&pNode1, 3);

	PrintListNode(pNode1);

	AddToTail(&pNode1, 100);
	PrintListNode(pNode1);

	ListNode* pNode100 = NULL; //ø’¡¥±Ì  
	AddToTail(&pNode100, 100);
	PrintListNode(pNode100);

	DestroyListNode(pNode1);

	return 0;
}
#endif // ListAddDelete