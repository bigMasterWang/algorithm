/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
*/

#include<vector>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

//class Solution {
//private:
//	void middleRecord(Node* node, vector<Node*>& nodeList)
//	{
//		if (!node)
//			return;
//		middleRecord(node->left, nodeList);
//		nodeList.push_back(node);
//		middleRecord(node->right, nodeList);
//	}
//public:
//	Node* treeToDoublyList(Node* root) {
//		if (!root)
//			return nullptr;
//		vector<Node*> nodeList;
//		middleRecord(root, nodeList);
//
//		Node* head = nodeList[0];
//		head->left = nullptr;
//		for (int i = 1; i < nodeList.size(); i++)
//		{
//			head->right = nodeList[i];
//			nodeList[i]->left = head;
//			head = nodeList[i];
//		}
//		head->right = nullptr;
//		return nodeList[0];
//	}
//};

class Solution {
private:
	Node* pre = new Node(0);

	void middleNode(Node* node)
	{
		if (!node)
			return;
		middleNode(node->left);
		pre->right = node;
		node->left = pre;
		pre = node;
		middleNode(node->right);
	}
public:
	Node* treeToDoublyList(Node* root) {
		if (!root)
			return nullptr;
		Node* saveHead = pre;
		middleNode(root);
		pre->right = saveHead->right;
		saveHead = saveHead->right;
		saveHead->left = pre;
		return saveHead;
	}
};