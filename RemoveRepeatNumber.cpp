#include<vector>
using namespace std;


// [0,0,1,1,1,2,2,3,3,4]
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int t = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0 || nums[i] != nums[i - 1])
				nums[t++] = nums[i];
		}
		return t;
	}
};