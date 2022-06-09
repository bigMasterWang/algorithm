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


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)	return nullptr;
		ListNode* slow = nullptr, * middle = head, * fast = head;
		while (fast->next)
		{
			fast = middle->next;
			middle->next = slow;
			slow = middle;
			middle = fast;
		}
		middle->next = slow;
		return middle;
	}
};