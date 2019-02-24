//#define _PrintTreeFromTopToBottom_
#ifdef _PrintTreeFromTopToBottom_

#include<iostream>
#include<queue>
#include<deque>
#include"06_BinaryTree.h"

using namespace std;

void PrintFromTopToBottom_queue(BinaryTreeNode* pRoot);
void PrintFromTopToBottom_deque(BinaryTreeNode* pRoot);
int main()
{
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

	PrintFromTopToBottom_queue(pNodeA1);
	PrintFromTopToBottom_deque(pNodeA1);

	return 0;
}

void PrintFromTopToBottom_queue(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return;
	queue<BinaryTreeNode*> queue;
	queue.push(pRoot);
	while (queue.size()) {
		BinaryTreeNode* pNode = queue.front();
		cout << pNode->m_nValue << " ";
		queue.pop();
		if (pNode->m_pLeft)
			queue.push(pNode->m_pLeft);
		if (pNode->m_pRight)
			queue.push(pNode->m_pRight);
	}
	cout << endl;
}
void PrintFromTopToBottom_deque(BinaryTreeNode* pRoot) {
	if (pRoot == NULL)
		return;
	deque<BinaryTreeNode*> deque;
	deque.push_back(pRoot);
	while (deque.size()) {
		BinaryTreeNode* pNode = deque.front();
		cout << pNode->m_nValue << " ";
		deque.pop_front();
		if (pNode->m_pLeft)
			deque.push_back(pNode->m_pLeft);
		if (pNode->m_pRight)
			deque.push_back(pNode->m_pRight);
	}
	cout << endl;
}
#endif // _PrintTreeFromTopToBottom_