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
//		// 1. ת��Ϊ�ַ���
//		// 2. �ж��Ƿ��ǻ���
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


// ʹ�����ַ�ת
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x / 10 == 0)
			return true;
		// 1. ���ַ�ת�� �ж����
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