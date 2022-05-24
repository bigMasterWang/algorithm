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
	vector<int> levelOrder(TreeNode* root) {
		vector<int>res;
		if (not root)
			return res;
		vector<TreeNode*> orderNodeVector;
		orderNodeVector.push_back(root);
		while (!orderNodeVector.empty())
		{
			TreeNode* t = orderNodeVector[0];
			res.push_back(t->val);
			orderNodeVector.erase(orderNodeVector.begin());
			if (t->left)
				orderNodeVector.push_back(t->left);
			if (t->right)
				orderNodeVector.push_back(t->right);
		}
		return res;
	}
};