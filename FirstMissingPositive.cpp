#include<vector>
using namespace std;


class Solution {
private:
	void exchange(int i, int j, vector<int>& v)
	{
		int x = v[i];
		v[i] = v[j];
		v[j] = x;
	}
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
			{
				exchange(i, nums[i] - 1, nums);
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
				return nums[i];
		}
	}
};