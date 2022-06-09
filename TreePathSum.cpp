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
#include<vector>
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
	vector<vector<int>> res;
	int targetValue;
	void dfs(TreeNode* node, vector<int>& path, int sum)
	{
		if (!node)
			return;
		if (!node->left && !node->right)
		{
			if (sum + node->val == targetValue)
			{
				path.push_back(node->val);
				res.push_back(path);
				path.pop_back();
			}
		}
		else
		{
			path.push_back(node->val);
			dfs(node->left, path, sum + node->val);
			dfs(node->right, path, sum + node->val);
			path.pop_back();
		}

	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		vector<int> path;
		targetValue = target;
		dfs(root, path, 0);
		return res;
	}
};