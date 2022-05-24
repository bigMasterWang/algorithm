#include<vector>
using namespace std;
/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1, m = 0;
		while (l < r)
		{
			m = (r + l) / 2;
			// 右边是有序的
			if (nums[m] < nums[r])
			{
				// 但是比右边最大的还大， 那就在左边, 比右边最小的还小, 在左边的无序中
				if (target > nums[r] || target < nums[m])
					r = m - 1;
				else if (target == nums[r])
					return r;
				else if (target < nums[r])
				{
					while (l < r)
					{
						m = (l + r) / 2;
						if (nums[m] == target)
							return m;
						if (nums[m] > target)
							r = m - 1;
						if (nums[m] < target)
							l = m + 1;
					}
					m = (l + r) / 2;
					if (nums[m] == target)
						return m;
					else
						return -1;
				}
			}
			else
			{
				// 左边是有序的, 比最小的还小， 在右边, 左边最大的还大， 在右边的无序中
				if (target < nums[l] || target > nums[m])
					l = m + 1;
				else if (target == nums[l])
					return l;
				else if (target > nums[l])
				{
					// 正常二分
					while (l < r)
					{
						m = (l + r) / 2;
						if (nums[m] == target)
							return m;
						if (nums[m] > target)
							r = m - 1;
						if (nums[m] < target)
							l = m + 1;
					}
					m = (l + r) / 2;
					if (nums[m] == target)
						return m;
					else
						return -1;
				}
			}
		}
		m = (l + r) / 2;
		if (nums[m] == target)
			return m;
		else
			return -1;
	}
};