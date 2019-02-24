//#define _19_MirrorOfBinaryTree_
#ifdef _19_MirrorOfBinaryTree_

#include<iostream>
#include<stack>
#include<queue>
#include"06_BinaryTree.h"

using namespace std;
// 递归实现
void Mirror_Recur(BinaryTreeNode* pNode);
// 循环实现（队列）
void Mirror_Queue(BinaryTreeNode* pNode);
// 循环实现（栈）
void Mirror_Stack(BinaryTreeNode* pNode);

int main()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	cout << "原始树：" << endl;
	PrintTree(pNode8);

	cout << "镜像树（递归）" << endl;
	Mirror_Recur(pNode8);
	PrintTree(pNode8);

	cout << "镜像树（循环，队列）" << endl;
	Mirror_Queue(pNode8);
	PrintTree(pNode8);

	cout << "镜像树（循环，栈）" << endl;
	Mirror_Stack(pNode8);
	PrintTree(pNode8);

	return 0;
}

void Mirror_Recur(BinaryTreeNode* pNode) {
	if (pNode == NULL || pNode->m_pLeft == NULL || pNode->m_pRight == NULL)
		return;
	BinaryTreeNode* p = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = p;
	if (pNode->m_pLeft != NULL)
		Mirror_Recur(pNode->m_pLeft);
	if (pNode->m_pRight != NULL)
		Mirror_Recur(pNode->m_pRight);
}
void Mirror_Queue(BinaryTreeNode* pNode) {
	if (pNode == NULL)
		return;
	queue<BinaryTreeNode*> q;
	q.push(pNode);
	while (!q.empty())
	{
		BinaryTreeNode* p = q.front();
		q.pop();
		if (p->m_pLeft != NULL)
			q.push(p->m_pLeft);
		if (p->m_pRight != NULL)
			q.push(p->m_pRight);
		BinaryTreeNode* ptemp = p->m_pLeft;
		p->m_pLeft = p->m_pRight;
		p->m_pRight = ptemp;
	}
}
void Mirror_Stack(BinaryTreeNode* pNode) {
	if (pNode == NULL)
		return;
	stack<BinaryTreeNode*> s;
	s.push(pNode);
	while (s.size()) {
		BinaryTreeNode* p = s.top();
		s.pop();
		if (p->m_pLeft != NULL || p->m_pRight != NULL) {
			BinaryTreeNode* ptemp = p->m_pLeft;
			p->m_pLeft = p->m_pRight;
			p->m_pRight = ptemp;
		}
		if (p->m_pLeft != NULL)
			s.push(p->m_pLeft);
		if (p->m_pRight != NULL)
			s.push(p->m_pRight);
	}
}
#endif // _19_MirrorOfBinaryTree_