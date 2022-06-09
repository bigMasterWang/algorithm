#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> numsStr;
		for (int x : nums)
			numsStr.push_back(to_string(x));
		auto cmp = [](string x, string y)
		{
			string xFirst = x + y;
			string yFirst = y + x;
			for (int i = 0; i < xFirst.size(); i++)
			{
				if (xFirst[i] - '0' == yFirst[i] - '0')
					continue;
				else if (xFirst[i] - '0' < yFirst[i] - '0')
					return true;
				else
					return false;
			}
			return true;
		};

		// 学到的东西, cmp中是小于返回true，大于返回false
		// 1. lambda的写法
		// 2. int转string
		sort(numsStr.begin(), numsStr.end(), cmp);
		string res = "";
		for (string s : numsStr)
			res += s;
		return res;
	}
};