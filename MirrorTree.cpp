/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
	TreeNode* mirrorTree(TreeNode* root)
	{
		if (!root)	return nullptr;
		TreeNode* res = new TreeNode(root->val);
		res->left = mirrorTree(root->right);
		res->right = mirrorTree(root->left);
		return res;
	}
};