/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
#include <cstddef>
#include<map>
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	// 先写完正常逻辑，最后处理特殊情况
	Node* copyRandomList(Node* head) {
		if (head == NULL)
			return head;

		Node* saveSrcHead = head;
		Node* newHead = new Node(head->val);
		Node* saveTarHead = newHead;

		// [7,null],[13,0],[11,4],[10,2],[1,0]

		std::map<Node*, Node*> valNode;
		valNode[head] = newHead;
		// 走一遍next
		while (head->next != NULL)
		{
			Node* n = new Node(head->next->val);
			newHead->next = n;
			newHead = n;
			head = head->next;
			valNode[head] = newHead;
		}

		// 走一遍random
		newHead = saveTarHead;
		head = saveSrcHead;
		while (head != NULL)
		{
			if (head->random == NULL)
				newHead->random = NULL;
			else
				newHead->random = valNode[head->random];
			newHead = newHead->next;
			head = head->next;
		}
		return saveTarHead;
	}
};