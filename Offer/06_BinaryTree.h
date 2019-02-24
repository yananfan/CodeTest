#pragma once
#include<iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
//创建树节点
BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	return pNode;
}
//创建树，连接节点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != NULL) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}
//打印树节点  
void PrintTreeNode(BinaryTreeNode* pNode) {
	if (pNode != NULL) {
		//cout << "the root is " << pNode->m_nValue << endl;
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft != NULL)
			//cout << "the left child is " << pNode->m_pLeft->m_nValue << endl;
			cout << pNode->m_pLeft->m_nValue << " ";
		else
			//cout << "the left child is null." << endl;
			cout << "#";
		if (pNode->m_pRight != NULL)
			//cout << "the right child is " << pNode->m_pRight->m_nValue << endl;
			cout << pNode->m_pRight->m_nValue << " ";
		else
			//cout << "the right child is null." << endl;
			cout << "#";
	}
	else
		cout << "the root node is null.";
	cout << endl;
}
//遍历树(前序)  
void PrintTree(BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);
	if (pRoot != NULL) {
		if (pRoot->m_pLeft != NULL)
			PrintTree(pRoot->m_pLeft);
		if (pRoot != NULL)
			PrintTree(pRoot->m_pRight);
	}
}
//销毁树  
void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;
		delete pRoot;
		pRoot = NULL;
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}