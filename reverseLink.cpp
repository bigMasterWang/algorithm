struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

#include<vector>
using namespace std;
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* nextNode = head->next;
		ListNode* nextNextNode = nextNode->next;
		head->next = nullptr;
		while (nextNextNode != NULL)
		{
			nextNode->next = head;
			head = nextNode;
			nextNode = nextNextNode;
			nextNextNode = nextNextNode->next;
		}
		nextNode->next = head;
		head = nextNode;
		return head;
	}
};