#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	bool isStraight(vector<int>& nums)
	{
		sort(nums.begin(), nums.end(), [](int x, int y) {return x < y; });
		int zeroNumber = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				zeroNumber++;
			else
			{
				if (i == 0)
					continue;
				if (nums[i] == nums[i - 1])
					return false;
				if (nums[i] == nums[i - 1] + 1)
					continue;
				if (nums[i] != nums[i - 1] + 1 && nums[i] - nums[i - 1] - 1 <= zeroNumber)
				{
					zeroNumber -= nums[i] - nums[i - 1] - 1;
					continue;
				}
				else
					return false;
			}
		}
		return true;
	}
};