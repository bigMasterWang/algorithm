#include<vector>
using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.size() == 1)
			return nums;
		int h = nums.size();
		vector<int> h_to_t(h), t_to_h(h);
		h_to_t[0] = nums[0];
		t_to_h[h - 1] = nums[h - 1];

		for (int i = 1; i < nums.size(); i++)
		{
			h_to_t[i] = nums[i] * h_to_t[i - 1];
			t_to_h[h - i - 1] = t_to_h[h - i] * nums[h - i - 1];
		}

		vector<int>res(h);
		res[0] = t_to_h[1];
		res[h - 1] = h_to_t[h - 1];
		for (int i = 1; i < nums.size(); i++)
			res[i] = h_to_t[i - 1] * t_to_h[i + 1];
		return res;
	}
};