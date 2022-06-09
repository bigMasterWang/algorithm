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
	ListNode* detectCycle(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* fastNode = head, * slowNode = head;
		while (fastNode && slowNode)
		{
			fastNode = fastNode->next;
			slowNode = slowNode->next;
			if (slowNode)
				slowNode = slowNode->next;
			else
				return nullptr;
			if (slowNode == fastNode)
				break;
		}
		if (slowNode != fastNode)
			return nullptr;
		fastNode = head;
		while (fastNode != slowNode)
		{
			fastNode = fastNode->next;
			slowNode = slowNode->next;
		}
		return slowNode;
	}
};