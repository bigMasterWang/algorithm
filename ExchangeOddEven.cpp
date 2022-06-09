#include<vector>
using namespace std;


class Solution {
public:

	// Ææ ... Å¼
	vector<int> exchange(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		vector<int> res(nums.size());

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 1)
				res[left++] = nums[i];
			else
				res[right--] = nums[i];
		}
		return res;
	}
};