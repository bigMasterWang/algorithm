#include<vector>
using namespace std;

/*
[1,2,3,0,0,0]
3
[2,5,6]
3
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int>res;
		int minLength = m < n ? m : n;
		int nums1Index = 0, nums2Index = 0;
		int i = 0;
		while (nums1Index < m && nums2Index < n)
		{
			if (nums1[nums1Index] < nums2[nums2Index])
				res.push_back(nums1[nums1Index++]);
			else
				res.push_back(nums2[nums2Index++]);
		}
		while (nums1Index < m)
			res.push_back(nums1[nums1Index++]);
		while (nums2Index < n)
			res.push_back(nums2[nums2Index++]);
		nums1.clear();
		nums1 = vector<int>(res);
	}
};