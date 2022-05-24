#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		// ��ָ�뷨
		if (nums.size() < 3)
			return vector<vector<int>>{};
		// 1. ��������
		vector<vector<int>> res;
		sort(nums.begin(), nums.end(), [](int x, int y) {return x < y; });

		for (int l = 0; l < nums.size(); l++)
		{
			if (l > 0 && nums[l] == nums[l - 1])
				continue;

			int r = nums.size() - 1;
			for (int m = l + 1; m < r; m++)
			{
				if (m > 1 + l && nums[m] == nums[m - 1])
					continue;
				while (m < r && nums[l] + nums[m] > -nums[r])
					r--;
				if (r == m)
					break;
				//��Ҫ��һ��r--������
				if (nums[l] + nums[m] == -nums[r])
					res.push_back(vector<int>{ nums[l], nums[m], nums[r] });
			}
		}
		return res;
	}
};