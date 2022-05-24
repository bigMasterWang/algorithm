#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;


		sort(nums.begin(), nums.end(), [](int x, int y) {return x < y; });


		int curMin = INT_MAX;
		int res = 0;
		for (int l = 0; l < nums.size(); l++)
		{
			int r = nums.size() - 1;
			for (int m = l + 1; m < r; m++)
			{
				while (-target + nums[l] + nums[r] + nums[m] > 0 && m < r)
				{
					if (abs(target - nums[l] - nums[r] - nums[m]) < curMin)
					{
						res = nums[l] + nums[r] + nums[m];
						curMin = abs(target - res);
					}
					r--;
				}
				if (r == m)
					break;
				if (abs(target - nums[l] - nums[r] - nums[m]) < curMin)
				{
					res = nums[l] + nums[r] + nums[m];
					curMin = abs(target - res);
				}
			}
		}
		return res;
	}
};