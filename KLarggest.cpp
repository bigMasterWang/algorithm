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
private:
	int res, k = 0;
	void middleNode(TreeNode* node)
	{
		if (!node || !k)
			return;
		middleNode(node->right);
		if (k == 0)
			return;
		if (--k == 0)
			res = node->val;
		middleNode(node->left);
	}
public:
	int kthLargest(TreeNode* root, int k) {
		this->k = k;
		middleNode(root);
		return res;
	}
};