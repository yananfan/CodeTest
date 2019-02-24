//#define _18_SubstructureInTree_
#ifdef _18_SubstructureInTree_

#include<iostream>
#include"06_BinaryTree.h"

using namespace std;
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

int main()
{
	// 剑指offer上的案例
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
	cout << "原始树A的前序遍历：" << endl;
	PrintTree(pNodeA1);
	cout << "原始树B的前序遍历：" << endl;
	PrintTree(pNodeB1);

	bool hastree = HasSubTree(pNodeA1, pNodeB1);
	if (hastree)
		cout << "树A中含有树B。" << endl;
	else
		cout << "树A中没有树B。" << endl;

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);

	return 0;
}
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	bool hastree = false;
	if (pRoot1 != NULL&&pRoot2 != NULL) {
		if (pRoot1->m_nValue == pRoot2->m_nValue)
			hastree = DoesTree1HasTree2(pRoot1, pRoot2);
		if (!hastree)
			hastree = HasSubTree(pRoot1->m_pLeft, pRoot2);
		if (!hastree)
			hastree = HasSubTree(pRoot1->m_pRight, pRoot2);
	}
	return hastree;
}
bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
#endif // _18_SubstructureInTree_