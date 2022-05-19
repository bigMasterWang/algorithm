#include<vector>
using namespace std;


// 暴力破解肯定不行， 要双指针
#include<algorithm>
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxWater = 0;
		int curWater = 0;
		int l = 0, r = height.size() - 1;
		while (l < r)
		{
			curWater = (r - l) * min(height[l], height[r]);
			maxWater = max(curWater, maxWater);
			if (height[l] <= height[r])
				l++;
			else
				r--;
		}
		return maxWater;
	}
};