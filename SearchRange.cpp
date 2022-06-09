#include<vector>
using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return { -1, -1 };
		vector<int>res;
		int first = -1, end = -1;
		int left = 0, right = nums.size() - 1, middle;
		while (left <= right)
		{
			middle = (left + right) / 2;
			if (nums[middle] == target)
				break;
			if (nums[middle] < target)
				left = middle + 1;
			else if (nums[middle] > target)
				right = middle - 1;
		}
		middle = (left + right) / 2;
		if (nums[middle] != target)
			return { -1, -1 };
		// 找到最开始的
		for (int j = middle; j >= 0; j--)
		{
			if (nums[middle] != nums[j])
				break;
			first = j;
		}
		for (int j = middle; j < nums.size(); j++)
		{
			if (nums[middle] != nums[j])
				break;
			end = j;
		}
		return { first, end };
	}
};