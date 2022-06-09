#include<vector>
using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int counter = 1, preValue = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			if (preValue == nums[i])
				counter++;
			else
				counter--;
			if (counter == 0)
			{
				preValue = nums[i];
				counter = 1;
			}
		}
		return preValue;
	}
};