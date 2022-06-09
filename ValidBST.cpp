/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<climits>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
private:
	bool validBST(TreeNode* root, long smallest, long biggest)
	{
		if (!root)
			return true;
		if (root->right && (root->right->val >= biggest || root->right->val <= root->val))
			return false;
		if (root->left && (root->left->val <= smallest || root->left->val >= root->val))
			return false;
		return validBST(root->left, smallest, root->val) && validBST(root->right, root->val, biggest);
	};
public:
	bool isValidBST(TreeNode* root) {
		return validBST(root, LONG_MIN, LONG_MAX);
	}
};