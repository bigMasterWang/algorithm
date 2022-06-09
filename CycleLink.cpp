/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};




class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (!head)
			return false;
		ListNode* sufNode = head;
		ListNode* preNode = head->next;
		while (preNode && sufNode)
		{
			sufNode = sufNode->next;
			preNode = preNode->next;
			if (preNode)
				preNode = preNode->next;
			if (preNode == sufNode)
				return true;
		}
		return false;
	}
};