//#define _CopyComplextList_
#ifdef _CopyComplextList_

#include<iostream>
#include<map>
#include"26_ComplexList.h"

using namespace std;

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);
ComplexListNode* Clone(ComplexListNode* pHead);
ComplexListNode* Clone_map(ComplexListNode* pHead);

int main()
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, NULL);
	BuildNodes(pNode4, pNode5, pNode2);

	cout << "The original list is: " << endl;
	PrintList(pNode1);

	ComplexListNode* pClonedHead = Clone(pNode1);

	cout << "The cloned list is: " << endl;
	PrintList(pClonedHead);

	ComplexListNode* pClonedHead_map = Clone_map(pNode1);

	cout << "The cloned list is: " << endl;
	PrintList(pClonedHead_map);

	return 0;
}

void CloneNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}
void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL) {
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL) {
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;
	if (pNode != NULL) {
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while (pNode != NULL) {
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}
ComplexListNode* Clone(ComplexListNode* pHead) {
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return
		ReconnectNodes(pHead);
}
ComplexListNode* Clone_map(ComplexListNode* pHead)
{
	if (pHead == NULL)  return NULL;
	map<ComplexListNode*, ComplexListNode*> pointMap;
	// newHead指向复制的新链表的开头，tail始终指向结尾
	ComplexListNode* newHead, *tail;
	// 开辟一个头结点
	newHead = new ComplexListNode;
	newHead->m_nValue = pHead->m_nValue;
	newHead->m_pNext = NULL;
	newHead->m_pSibling = NULL;
	// 将头结点放入map中
	pointMap[pHead] = newHead;

	tail = newHead;
	ComplexListNode *p = pHead->m_pNext;
	// 第一遍先将简单链表复制一下
	while (p != NULL)
	{
		ComplexListNode* newNode = new ComplexListNode;
		newNode->m_nValue = p->m_nValue;
		newNode->m_pNext = NULL;
		newNode->m_pSibling = NULL;

		tail->m_pNext = newNode;
		tail = newNode;
		pointMap[p] = newNode;
		p = p->m_pNext;
	}

	// 根据map中保存的数据，找到对应的节点
	p = pHead;
	tail = newHead;
	while (p != NULL)
	{
		if (p->m_pSibling != NULL)
		{
			tail->m_pSibling = pointMap.find(p->m_pSibling)->second;
		}
		p = p->m_pNext;
		tail = tail->m_pNext;
	}
	return newHead;
}
#endif // _CopyComplextList_