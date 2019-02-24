//#define _PathInTree_
#ifdef _PathInTree_

#include<iostream>
#include"06_BinaryTree.h"
#include<vector>

using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int& currentSum);
void FindPath(BinaryTreeNode* pRoot, int expectedSum);

int main()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	FindPath(pNode10, 22);

	return 0;
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int& currentSum) {
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	bool isLeaf = pRoot->m_pLeft == NULL&&pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf) {
		cout << "One Path is found: ";
		vector<int>::iterator iter = path.begin();
		for (;iter != path.end();iter++)
			cout << *iter << " ";
		cout << endl;
	}
	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
	if (pRoot == NULL)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}
#endif // _PathInTree_