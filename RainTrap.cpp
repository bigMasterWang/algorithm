#include<vector>
using namespace std;


class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> headH;
		vector<int> tailH;

		int mH = -1, hIndex = -1;
		for (int i = 0; i < height.size(); i++)
		{
			if (mH <= height[i])
				mH = height[i];
			headH.push_back(mH);
		}
		mH = -1, hIndex = -1;
		for (int i = height.size() - 1; i >= 0; i--)
		{
			if (mH <= height[i])
				mH = height[i];
			tailH.push_back(mH);
		}
		int water = 0;
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = 1; j < mH; j++)
			{
				if (height[i] >= j)
					continue;
				if (headH[i] > j&& tailH[i] > j)
					water += 1;
			}
		}
		return water;
	}
};