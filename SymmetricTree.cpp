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
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	bool judgeSymmetric(TreeNode* a, TreeNode* b)
	{
		if (!a && !b)
			return true;
		if ((!a && b) || (a && !b))
			return false;
		return (a->val == b->val) && judgeSymmetric(a->left, b->right) && judgeSymmetric(a->right, b->left);
	}
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return false;
		return judgeSymmetric(root, root);
	}
};