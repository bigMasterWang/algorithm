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
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
*/

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || !head)
			return head;

		// k会大于链表的长度， 算出链表的长度
		ListNode* lengthHead = head;
		int l = 1;
		while (lengthHead->next)
		{
			lengthHead = lengthHead->next;
			l++;
		}

		ListNode* lHead = head;
		ListNode* rHead = head;

		k = k % l;
		for (int i = 0; i < k; i++)
			rHead = rHead->next;
		while (rHead->next)
		{
			rHead = rHead->next;
			lHead = lHead->next;
		}
		rHead->next = head;
		ListNode* res = lHead->next;
		lHead->next = nullptr;
		return res;
	}
};