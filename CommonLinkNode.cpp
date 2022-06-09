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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB)
			return nullptr;
		ListNode* pA = headA, * pB = headB;
		bool changedA = false, changedB = false;
		while (pA != pB && pA && pB)
		{
			pA = pA->next;
			pB = pB->next;
			if (!pA)
			{
				if (!changedA)
					pA = headB;
				changedA = true;
			}
			if (!pB && !changedB)
			{
				pB = headA;
				changedB = true;
			}
		}
		return pA;
	}
};