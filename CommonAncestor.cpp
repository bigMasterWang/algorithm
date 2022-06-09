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
private:
	int bV, lV;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return nullptr;
		bV = p->val > q->val ? p->val : q->val;
		lV = p->val < q->val ? p->val : q->val;

		if (root->val >= lV && root->val <= bV)
			return root;
		else if (root->val < lV)
			return lowestCommonAncestor(root->right, p, q);
		else
			return lowestCommonAncestor(root->left, p, q);
	}
};