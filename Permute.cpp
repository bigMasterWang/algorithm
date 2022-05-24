#include<vector>
using namespace std;


class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;

	void backtrack(vector<int>& nums, vector<bool>& used)
	{
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i])
				continue;
			path.push_back(nums[i]);
			used[i] = true;
			backtrack(nums, used);
			used[i] = false;
			path.pop_back();
		}
	}


public:
	vector<vector<int>> permute(vector<int>& nums) {

		// fixme vector的一种初始化方法
		vector<bool> used(nums.size(), false);
		backtrack(nums, used);
		return res;
	}
};