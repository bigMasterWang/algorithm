#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		map<int, int> recorder;
		for (int i : nums)
		{
			recorder[i] = 0;
		}
		for (int i : nums)
		{
			recorder[i] += 1;
		}

		for (int i : nums)
		{
			if (recorder[i] >= 2)
				return i;
		}
		return 0;
	}
};