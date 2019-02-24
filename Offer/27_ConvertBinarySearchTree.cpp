//#define _ConvertBinarySearchTree_
#ifdef _ConvertBinarySearchTree_

#include<iostream>
#include"06_BinaryTree.h"

using namespace std;

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree);
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList);

int main()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	PrintTree(pNode10);
	BinaryTreeNode* pHeadOfList = Convert(pNode10);
	PrintDoubleLinkedList(pHeadOfList);

	return 0;
}
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
	if (pNode == NULL)
		return;

	BinaryTreeNode* pCurrent = pNode;

	if (pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;

	*pLastNodeInList = pCurrent;
	if (pCurrent->m_pRight != NULL)
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	BinaryTreeNode* pLastNodeINList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeINList);

	BinaryTreeNode* pHeadOfList = pLastNodeINList;
	while (pHeadOfList != NULL&&pHeadOfList->m_pLeft != NULL)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	cout << "The nodes from left to right are: " << endl;
	while (pNode != NULL)
	{
		cout << pNode->m_nValue << " ";

		if (pNode->m_pRight == NULL)
			break;
		pNode = pNode->m_pRight;
	}

	cout << endl << "The nodes from right to left are: " << endl;
	while (pNode != NULL)
	{
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft == NULL)
			break;
		pNode = pNode->m_pLeft;
	}
	cout << endl;
}
#endif // _ConvertBinarySearchTree_