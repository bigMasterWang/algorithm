
#include<vector>
class Solution {
public:
	// 假设环境不允许存储 64 位整数
	// 还有可能是负数
	int reverse(int x) {
		bool flag = 1;
		if (x < 0)
		{
			x *= -1;
			flag = -1;
		}
		std::vector<int> nums;
		while (x)
		{
			int v = x % 10;
			nums.push_back(v);
			x /= 10;
		}
		// 2147483648
		// 2147483647
		// 2147483648
		int _w = 1;
		int res = 0;
		try
		{
			for (int i = nums.size() - 1; i >= 0; i--)
			{
				res += nums[i] * _w;
				_w *= 10;
			}
		}
		catch (const char* ptr)
		{
			return 0;
		}
		return res * flag;
	}
};