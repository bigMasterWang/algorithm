/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* preHead = new ListNode(0);
		ListNode* saveHead = preHead;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				preHead->next = l1;
				preHead = l1;
				l1 = l1->next;
			}
			else
			{
				preHead->next = l2;
				preHead = l2;
				l2 = l2->next;
			}
		}
		if (l1)
			preHead->next = l1;
		if (l2)
			preHead->next = l2;
		return saveHead->next;
	}
};