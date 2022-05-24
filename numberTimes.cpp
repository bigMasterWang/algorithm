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


// 二分查找, 
// 推出循环后， 直接_index = (l+r) / 2即可
// while 是 < == break  < l = middle + 1, > r = middle-1
class Solution {
public:
	int search(vector<int>& nums, int target) {
		// 写一个二分查找
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
		// 那么出来了， 总共就有两种情况
		// _index = target, l == r, 所以再执行一次 _index = (r+l)/2 即可
		_index = (l + r) / 2;
		int timer = 0;
		for (int i = _index; i < nums.size() && nums[i] == target; i++)
			timer += 1;
		for (int i = _index - 1; i >= 0 && nums[i] == target; i--)
			timer += 1;
		return timer;
	}
};