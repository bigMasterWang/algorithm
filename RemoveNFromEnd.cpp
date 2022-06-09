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



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


// 删除链表的第k个节点
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head->next)
		{
			if (n == 0)
				return head;
			if (n == 1)
				return nullptr;
		}
		ListNode* opRightHead = head, * opLeftHead = head;
		for (int i = 0; i < n; i++)
		{
			opRightHead = opRightHead->next;
		}
		if (!opRightHead)
			return head->next;
		while (opRightHead->next)
		{
			opRightHead = opRightHead->next;
			opLeftHead = opLeftHead->next;
		}
		if (opLeftHead->next)
		{
			opLeftHead->next = opLeftHead->next->next;
		}
		return head;
	}
};