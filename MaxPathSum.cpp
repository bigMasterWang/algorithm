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


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include<vector>
#include <algorithm>
#include<climits>
using namespace std;


class Solution {
private:
	int maxSum = INT_MIN;

	int findMaxSub(TreeNode* node)
	{
		if (!node)
			return 0;
		int leftSum = max(findMaxSub(node->left), 0);
		int rightSum = max(findMaxSub(node->right), 0);

		int nodeSum = node->val + leftSum + rightSum;
		maxSum = max(maxSum, nodeSum);
		return node->val + max(leftSum, rightSum);
	}

public:
	int maxPathSum(TreeNode* root) {
		findMaxSub(root);
		return maxSum;
	}
};