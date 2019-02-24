#pragma once
#include<iostream>

using namespace std;
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};
ComplexListNode* CreateNode(int nValue) {
	ComplexListNode* pNode = new ComplexListNode();
	pNode->m_nValue = nValue;
	pNode->m_pNext = NULL;
	pNode->m_pSibling = NULL;
	return pNode;
}
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling) {
	if (pNode == NULL)
		return;
	pNode->m_pNext = pNext;
	pNode->m_pSibling = pSibling;
}
void PrintList(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		cout << "this node value: " << pNode->m_nValue << endl;
		if (pNode->m_pSibling != NULL)
			cout << "sibling value: " << pNode->m_pSibling->m_nValue << endl;
		else
			cout << "no sibling node." << endl;
		pNode = pNode->m_pNext;
	}
}