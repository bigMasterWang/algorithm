#include<vector>
#include<map>
using namespace std;

//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int timer = 0;
//		for (int n : nums)
//		{
//			if (n == target)
//				timer += 1;
//		}
//		return timer;
//	}
//};


// ���ֲ���, 
// �Ƴ�ѭ���� ֱ��_index = (l+r) / 2����
// while �� < == break  < l = middle + 1, > r = middle-1
class Solution {
public:
	int search(vector<int>& nums, int target) {
		// дһ�����ֲ���
		int l = 0, r = nums.size() - 1, _index = 0;
		while (l < r)
		{
			_index = (l + r) / 2;
			if (nums[_index] == target)
				break;
			if (nums[_index] < target)
				l = _index + 1;
			if (nums[_index] > target)
				r = _index - 1;
		}
		// ��ô�����ˣ� �ܹ������������
		// _index = target, l == r, ������ִ��һ�� _index = (r+l)/2 ����
		_index = (l + r) / 2;
		int timer = 0;
		for (int i = _index; i < nums.size() && nums[i] == target; i++)
			timer += 1;
		for (int i = _index - 1; i >= 0 && nums[i] == target; i--)
			timer += 1;
		return timer;
	}
};