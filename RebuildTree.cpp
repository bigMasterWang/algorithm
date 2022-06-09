/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);
		vector<int>preorderLeft;
		vector<int>preorderRight;

		vector<int>inorderLeft;
		vector<int>inorderRight;

		bool left = true;
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == preorder[0])
				left = false;
			else if (left)
				inorderLeft.push_back(inorder[i]);
			else
				inorderRight.push_back(inorder[i]);
		}

		for (int i = 0; i < inorderLeft.size(); i++)
			preorderLeft.push_back(preorder[i + 1]);

		for (int i = 1 + inorderLeft.size(); i < preorder.size(); i++)
			preorderRight.push_back(preorder[i]);
		root->left = buildTree(preorderLeft, inorderLeft);
		root->right = buildTree(preorderRight, inorderRight);
		return root;
	}
};