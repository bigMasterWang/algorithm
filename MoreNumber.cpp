#include<vector>
using namespace std;

// [1,2,3,2,2,2,5,4,2]
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int number = 1;
		int value = nums[0];
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return value;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == value)
				number++;
			else
				number--;
			if (number == 0)
			{
				value = nums[i];
				number = 1;
			}
		}
		return value;
	}
};