#include<vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int l = 0, r = nums.size() - 1, middle = 0;
		while (l < r)
		{
			middle = (l + r) / 2;
			if (nums[middle] == middle)
				l = middle + 1;
			if (nums[middle] > middle)
				r = middle - 1;

		}
		middle = (l + r) / 2;
		if (nums[middle] == middle)
			return middle + 1;
		else if (nums[middle] < middle)
			return 0;
		return middle;
	}
};