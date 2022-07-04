#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
private:
	bool isNumber(char x)
	{
		return (x - '0' >= 0 && x - '0' <= 9);
	}
public:
	int strToInt(string str) {
		str.erase(0, str.find_first_not_of(' '));
		string num = "";
		bool negative = false;
		if (str[0] == '-')
			negative = true;
		else if (str[0] == '+')
			negative = false;
		else if (isNumber(str[0]))
			num += str[0];
		else
			return 0;
		for (int i = 1; i < str.size(); i++)
		{
			if (!isNumber(str[i]))
				break;
			num += str[i];
		}

		long long res = 0;
		for (int i = 0; i < num.size(); i++)
		{
			res *= 10;
			res += (num[i] - '0');
			if (negative)
			{
				if (-res <= INT_MIN)
					return INT_MIN;
			}
			else if (res >= INT_MAX)
				return INT_MAX;
		}
		if (negative)
			return -res;
		return res;
	}
};
int main()
{
	Solution s;
	std::cout << s.strToInt("-0012a42");
}