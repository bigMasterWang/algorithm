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
#include<map>
#include<algorithm>
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
	ListNode* fastNode, * slowNode;
public:
	// �ҵ��м�ڵ㣬 Ȼ����ߵݹ�鲢�� �ұ�Ҳ�ݹ�鲢
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
			return head;

		fastNode = head;
		slowNode = head;
		while (fastNode)
		{
			fastNode = fastNode->next;
			if (!fastNode)
				break;
			fastNode = fastNode->next;
			if (!fastNode)
				break;
			slowNode = slowNode->next;
		}
		ListNode* rightHead = slowNode->next;
		slowNode->next = nullptr;

		ListNode* left = sortList(head);
		ListNode* right = sortList(rightHead);
		// �鲢
		ListNode* newHead = new ListNode();
		ListNode* saveHead = newHead;
		while (right && left)
		{
			if (right->val < left->val)
			{
				newHead->next = right;
				newHead = right;
				right = right->next;
			}
			else
			{
				newHead->next = left;
				newHead = left;
				left = left->next;
			}
		}
		while (right)
		{
			newHead->next = right;
			newHead = right;
			right = right->next;
		}
		while (left)
		{
			newHead->next = left;
			newHead = left;
			left = left->next;
		}
		return saveHead->next;
	}
};