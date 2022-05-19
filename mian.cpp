#include<iostream>
#include<string>
using namespace std;


#include<vector>
#include<limits>
class Solution {
public:
	int myAtoi(string s) {
		// 空格， 正负， 实际数字前的0
		long res = 0, flag = 1;
		bool hasNumber = false;
		bool hasFlag = false;
		for (char x : s)
		{
			// 消除前导空格
			if (x == ' ' && !hasNumber && !hasFlag)
				continue;
			// 数字前的正负号
			if (x == '+' and !hasFlag && !hasNumber)
			{
				hasFlag = true;
				continue;
			}
			if (x == '-' and !hasFlag && !hasNumber)
			{
				hasFlag = true;
				flag = -1;
				continue;
			}
			if (x - 48 < 0 || x - 48 > 9)
				break;
			hasNumber = true;
			res = res * 10 + x - 48;
			if (res * flag > INT_MAX)
				return INT_MAX;
			if (res * flag < INT_MIN)
				return INT_MIN;
		}
		return res * flag;
	}
};

int main()
{
	Solution s;
	// 2147483647
	// 1534236469
	std::cout << char(1 + 48);
}