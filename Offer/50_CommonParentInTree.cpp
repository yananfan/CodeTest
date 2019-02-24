//#define _CommonParentInTree_
#ifdef _CommonParentInTree_

#include<iostream>
#include<list>
#include"50_Tree.h"
using namespace std;

bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path);
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2);
TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2);
int main()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	TreeNode* pResult = GetLastCommonParent(pNode1, pNode6, pNode5);
	cout << pNode6->m_nValue << " 和 " << pNode5->m_nValue << " 的最低公共祖先是： " << pResult->m_nValue << endl;
	return 0;
}
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path) {
	if (pRoot == pNode)
		return true;
	path.push_back(pRoot);
	bool found = false;
	vector<TreeNode*>::iterator iter = pRoot->m_pChildren.begin();
	while (!found && iter < pRoot->m_pChildren.end()) {
		found = GetNodePath(*iter, pNode, path);
		iter++;
	}
	if (!found)
		path.pop_back();
	return found;
}
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2) {
	list<TreeNode*>::const_iterator iter1 = path1.begin();
	list<TreeNode*>::const_iterator iter2 = path2.begin();
	TreeNode* pLast = NULL;
	while (iter1 != path1.end() && iter2 != path2.end()) {
		if (*iter1 == *iter2)
			pLast = *iter1;
		iter1++;
		iter2++;
	}
	return pLast;
}
TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2) {
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;
	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);
	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);
	return GetLastCommonNode(path1, path2);
}
#endif // _CommonParentInTree_