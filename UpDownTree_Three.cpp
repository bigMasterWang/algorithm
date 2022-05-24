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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		vector<TreeNode*> orderTreeNode;
		vector<int> level;
		orderTreeNode.push_back(root);
		orderTreeNode.push_back(new TreeNode(101));
		bool leftToRight = true;
		while (!orderTreeNode.empty())
		{
			TreeNode* t = orderTreeNode[0];
			orderTreeNode.erase(orderTreeNode.begin());

			if (t->val == 101 && !t->left && !t->right)
			{
				// 左右反转记得
				if (!leftToRight)
				{
					reverse(level.begin(), level.end());
				}
				res.push_back(level);
				level = vector<int>();
				orderTreeNode.push_back(new TreeNode(101));
				leftToRight = !leftToRight;
				if (orderTreeNode.size() == 1)
					break;
				continue;
			}

			level.push_back(t->val);
			if (t->left)
				orderTreeNode.push_back(t->left);
			if (t->right)
				orderTreeNode.push_back(t->right);
		}
		return res;
	}
};