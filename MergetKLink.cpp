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
	struct MyNode {
		int val;
		ListNode* node;
		MyNode() : val(0), node(nullptr) {};
		MyNode(int _v, ListNode* h) : val(_v), node(h) {};
		bool operator <(const MyNode& r) const
		{
			return val > r.val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		{
			ListNode head, * tail = &head;
			priority_queue<MyNode> _priority_queue;
			for (ListNode* h : lists)
				if (h)
					_priority_queue.push(MyNode{ h->val, h });
			while (!_priority_queue.empty())
			{
				auto f = _priority_queue.top();
				_priority_queue.pop();
				tail->next = f.node;
				tail = tail->next;
				if (f.node->next)
					_priority_queue.push(MyNode{ f.node->next->val, f.node->next });
			}
			return head.next;
		}
	}
};

//class Solution {
//private:
//	ListNode* mergeTwoLists(ListNode* head_1, ListNode* head_2)
//	{
//		if (head_1 == nullptr && head_2 == nullptr)
//			return nullptr;
//		if (head_1 == nullptr)
//			return head_2;
//		if (head_2 == nullptr)
//			return head_1;
//		ListNode* res, * save_res;
//		if (head_1->val <= head_2->val)
//		{
//			res = head_1;
//			head_1 = head_1->next;
//		}
//		else
//		{
//			res = head_2;
//			head_2 = head_2->next;
//		}
//		save_res = res;
//		while (head_1 && head_2)
//		{
//			if (head_1->val <= head_2->val)
//			{
//				res->next = head_1;
//				res = head_1;
//				head_1 = head_1->next;
//			}
//			else
//			{
//				res->next = head_2;
//				res = head_2;
//				head_2 = head_2->next;
//			}
//		}
//		while (head_1)
//		{
//			res->next = head_1;
//			res = head_1;
//			head_1 = head_1->next;
//		}
//		while (head_2)
//		{
//			res->next = head_2;
//			res = head_2;
//			head_2 = head_2->next;
//		}
//		return save_res;
//	}
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.size() == 0)
//			return nullptr;
//		// Ñ­»·£¬ Á½Á½merge
//		ListNode* head = lists[0];
//		for (int i = 1; i < lists.size(); i++)
//		{
//			head = mergeTwoLists(head, lists[i]);
//		}
//		return head;
//	}
//};