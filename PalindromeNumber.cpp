#include<string>
#include<vector>
using namespace std;

//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x < 0)
//			return false;
//		if (x / 10 == 0)
//			return true;
//		// 1. 转化为字符串
//		// 2. 判断是否是回文
//		vector<char> nums;
//		while (x)
//		{
//			nums.push_back(char((x % 10) + 48));
//			x /= 10;
//		}
//		for (int i = 0, j = nums.size() - 1; i <= j; i++, j--)
//		{
//			if (nums[i] != nums[j])
//				return false;
//		}
//		return true;
//	}
//};


// 使用数字反转
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x / 10 == 0)
			return true;
		// 1. 数字反转， 判断相等
		int save = x;
		long res = 0;
		while (x)
		{
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res == save;
	}
};