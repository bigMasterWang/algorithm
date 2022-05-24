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
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//class Solution {
//private:
//	int curDepth = 0, _maxDepth = 0;
//	void searchDepth(TreeNode* node)
//	{
//		if (!node)
//			return;
//		curDepth += 1;
//		_maxDepth = curDepth > _maxDepth ? curDepth : _maxDepth;
//		searchDepth(node->left);
//		searchDepth(node->right);
//		curDepth -= 1;
//	}
//public:
//	int maxDepth(TreeNode* root) {
//		searchDepth(root);
//		return _maxDepth;
//	}
//};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};