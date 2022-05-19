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

#include<vector>
using namespace std;
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		if (head->next == nullptr)
		{
			return vector<int>{head->val};
		}
		ListNode* nextNode = head->next;
		ListNode* nextNextNode = nextNode->next;
		head->next = nullptr;
		while (nextNextNode != nullptr)
		{
			nextNode->next = head;
			head = nextNode;
			nextNode = nextNextNode;
			nextNextNode = nextNextNode->next;
		}
		nextNode->next = head;
		head = nextNode;

		vector<int> res;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}
		return res;
	}
};