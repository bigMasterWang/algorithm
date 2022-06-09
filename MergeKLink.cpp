/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
#include<queue>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
private:
	struct MyNode
	{
		int val;
		ListNode* node;
		MyNode() : val(0), node(nullptr) {};
		MyNode(int x, ListNode* n) : val(x), node(n) {};
		bool operator < (const MyNode& node) const
		{
			return val > node.val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head, * tail = &head;
		priority_queue<MyNode> pq;
		for (ListNode* n : lists)
			if (n)
				pq.push(MyNode(n->val, n));
		while (!pq.empty())
		{
			MyNode n = pq.top();
			pq.pop();
			tail->next = n.node;
			tail = tail->next;
			if (n.node->next)
				pq.push(MyNode(n.node->next->val, n.node->next));
		}
		return head.next;
	}
};