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
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
private:
	bool res = true;
	int subTreeDepth(TreeNode* node)
	{
		if (!node)
			return 0;
		int leftDepth = subTreeDepth(node->left);
		int rightDepth = subTreeDepth(node->right);
		if (abs(leftDepth - rightDepth) > 1)
			res = false;
		return max(leftDepth, rightDepth) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		subTreeDepth(root);
		return res;
	}
};