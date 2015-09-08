//根据前序和中序序列构造二叉树

#include "stdafx.h"
#include<vector>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
	//判断终止条件
	if(pre.size() == 0 || in.size() ==0 ) return NULL;

	//定义根节点
	int root = pre[0];
	TreeNode * node = new TreeNode(root);

	//求左右子树的遍历序列
	vector<int> preLeft,preRight,inLeft,inRight;
		//求根节点在中序序列中的位置
	int rootIndex = 0;
	int leftLength = 0;

	for(int i=0; i<in.size();i++) {
		if(in.at(i) == root) {
			rootIndex = i;
			break;
		}
	}
	leftLength = rootIndex;
		//求左右子树的前序遍历序列
	for(int i= 1; i <= leftLength; i++) {
		preLeft.push_back(pre[i]);
	}
	for(int i= leftLength+1; i<pre.size(); i++) {
		preRight.push_back(pre[i]);
	}

		//求左右子树的中序遍历序列
	for(int i = 0; i<leftLength; i++) {
		inLeft.push_back(in[i]);
	}
	for(int i = leftLength+1;i<in.size();i++) {
		inRight.push_back(in[i]);
	}

	node->left = reConstructBinaryTree(preLeft,inLeft);
	node->right = reConstructBinaryTree(preRight,inRight);
	return node;
}
