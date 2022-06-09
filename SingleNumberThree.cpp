#include<vector>
using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int>k(32, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < 32; j++)
			{
				k[j] += (nums[i] >> j) & 1;
			}
		}

		int res = 0;
		for (int i = 31; i >= 0; i--)
		{
			res <<= 1;
			if (k[i] % 3 == 1)
				res += 1;
		}
		return res;
	}
};