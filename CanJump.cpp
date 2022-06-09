#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int>dp(nums.size(), -1);
		dp[0] = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			if (dp[i - 1] >= i)
				dp[i] = max(dp[i - 1], i + nums[i]);
			else
				return false;
		}
		return dp[nums.size() - 1] != -1;
	}
};