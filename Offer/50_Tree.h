#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int m_nValue;
	vector<TreeNode*> m_pChildren;
};

TreeNode* CreateTreeNode(int value) {
	TreeNode* pNew = new TreeNode();
	pNew->m_nValue = value;
	return pNew;
}
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild) {
	if (pParent != NULL)
		pParent->m_pChildren.push_back(pChild);
}
void PrintTreeNode(TreeNode* pNode) {
	if (pNode != NULL) {
		cout << "root:" << endl;
		cout << pNode->m_nValue;
		cout << "children: " << endl;
		vector<TreeNode*>::iterator iter = pNode->m_pChildren.begin();
		while (iter < pNode->m_pChildren.end()) {
			if (*iter != NULL)
				cout << (*iter)->m_nValue << " ";
		}
		cout << endl;
	}
	else
		cout << " null ";
	cout << endl;
}
void PrintTree(TreeNode* pRoot) {
	PrintTreeNode(pRoot);
	if (pRoot != NULL) {
		vector<TreeNode*>::iterator iter = pRoot->m_pChildren.begin();        
		while (iter < pRoot->m_pChildren.end())
		{
			PrintTree(*iter);
			iter++;
		}
	}
}
void DestroyTree(TreeNode* pRoot) {
	if (pRoot != NULL) {
		vector<TreeNode*>::iterator iter = pRoot->m_pChildren.begin();
		while (iter < pRoot->m_pChildren.end()) {
			DestroyTree(*iter);
			iter++;
		}
		delete pRoot;
	}
}