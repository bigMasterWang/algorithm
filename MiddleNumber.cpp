#include<vector>
using namespace std;



class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// 1. 合并有序数组
		int n1 = 0, n2 = 0;
		vector<int> numsRes;
		while (n1 < nums1.size() && n2 < nums2.size())
		{
			if (nums1[n1] <= nums2[n2])
				numsRes.push_back(nums1[n1++]);
			else
				numsRes.push_back(nums2[n2++]);
		}
		// 有可能有一个没有走完, 没走完的都是大的
		while (n1 < nums1.size())
			numsRes.push_back(nums1[n1++]);
		while (n2 < nums2.size())
			numsRes.push_back(nums2[n2++]);

		// 2.算出中位数
		// 如果是奇数， 返回size/2, 否则返回（size/2, size/2+1）/2
		int _l = numsRes.size();
		if (_l % 2 == 1)
			return numsRes[_l / 2];
		return (numsRes[_l / 2] + numsRes[_l / 2 - 1]) / 2.0;
	}
};