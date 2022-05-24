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
	bool judgeSubTree(TreeNode* A, TreeNode* B)
	{
		if (!B)
			return true;
		if (!A)
			return false;
		if (A->val != B->val)
			return false;
		return judgeSubTree(A->left, B->left) && judgeSubTree(A->right, B->right);
	}
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (!A || !B)
			return false;
		return judgeSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};