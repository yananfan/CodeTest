//#define _TreeDepth_
#ifdef _TreeDepth_

#include<iostream>
#include"06_BinaryTree.h"
using namespace std;
// 二叉树的深度
int TreeDepth(BinaryTreeNode* pRoot);
// 判断平衡二叉树
bool IsBalanced_1(BinaryTreeNode* pRoot);
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth);
bool IsBalanced_2(BinaryTreeNode* pRoot);
int main()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, NULL, pNode6);
	ConnectTreeNodes(pNode5, pNode7, NULL);

	int depth = TreeDepth(pNode1);
	cout << "树的深度是： " << depth << endl;

	bool balance1 = IsBalanced_1(pNode1);
	bool balance2 = IsBalanced_2(pNode1);
	cout << "balance1 = " << balance1 << endl;
	cout << "balance2 = " << balance2 << endl;

	return 0;
}
int TreeDepth(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return 0;
	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	return (left > right) ? (left + 1) : (right + 1);
}
bool IsBalanced_1(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return true;
	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);
	int diff = left - right;
	if (diff > 1 || diff < -1)
		return false;
	return IsBalanced_1(pRoot->m_pLeft) && IsBalanced_1(pRoot->m_pRight);
}
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth) {
	if (pRoot == NULL) {
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
bool IsBalanced_2(BinaryTreeNode* pRoot) {
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}
#endif // _TreeDepth_