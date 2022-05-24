#include<vector>
using namespace std;


class Solution {
	vector<int>path;
	vector<vector<int>>res;
private:
	void search(vector<int>& nums, int start)
	{
		if (start == nums.size())
			return;
		for (int i = start; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			res.push_back(path);
			search(nums, i + 1);
			path.pop_back();
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0)
			return res;
		search(nums, 0);
		res.push_back(vector<int>());
		return res;
	}
};