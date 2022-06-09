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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (!head)
			return head;
		ListNode* preHead = head;
		for (int i = 0; i < k; i++)
		{
			preHead = preHead->next;
		}
		while (preHead)
		{
			preHead = preHead->next;
			head = head->next;
		}
		return head;
	}
};