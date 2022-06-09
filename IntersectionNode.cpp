/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* pA = headA, * pB = headB;
		bool aChanged = false, bChanged = false;
		while (pA && pB)
		{
			if (pA == pB)
				return pA;
			pA = pA->next;
			pB = pB->next;
			if (!pA)
			{
				if (aChanged)
					break;
				pA = headB;
				aChanged = true;
			}
			if (!pB)
			{
				if (bChanged)
					break;
				pB = headA;
				bChanged = true;
			}
		}
		return nullptr;
	}
};