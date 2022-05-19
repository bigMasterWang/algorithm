using namespace std;


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
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
private:
	ListNode* reverseListNode(ListNode* l)
	{
		if (l == nullptr || l->next == nullptr)
			return l;
		ListNode* nextNode = l->next;
		ListNode* nextNextNode = nextNode->next;
		l->next = nullptr;
		while (nextNextNode != nullptr)
		{
			nextNode->next = l;
			l = nextNode;
			nextNode = nextNextNode;
			nextNextNode = nextNode->next;
		}
		nextNode->next = l;
		l = nextNode;
		return l;
	}
public:
	// [2,4,3] -> 3, 4, 2, 4
	// [5,6,4] -> 4, 5, 6
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// 特殊情况判断
		// 顺序相加
		ListNode* _c_l1 = l1;
		ListNode* _c_l2 = l2;
		ListNode* res = new ListNode();
		ListNode* save_res = res;
		int add = 0;
		while (_c_l1 != nullptr && _c_l2 != nullptr)
		{
			int v = _c_l1->val + _c_l2->val + add;
			res->val = v % 10;
			add = v / 10;

			_c_l1 = _c_l1->next;
			_c_l2 = _c_l2->next;
			res->next = new ListNode();
			res = res->next;
		}
		// 谁不为null， 就继续加下去
		while (_c_l1 != nullptr)
		{
			int v = _c_l1->val + add;
			res->val = v % 10;
			add = v / 10;
			_c_l1->next = _c_l1;
			res->next = new ListNode();
			res = res->next;
		}
		while (_c_l2 != nullptr)
		{
			int v = _c_l2->val + add;
			res->val = v % 10;
			add = v / 10;
			_c_l2 = _c_l2;
			res->next = new ListNode();
			res = res->next;
		}
		// 应该不会超过10
		if (add != 0)
			res->val = add;
		res = reverseListNode(save_res);
		if (res->val == 0)
			res = res->next;
		return reverseListNode(res);
	}
};