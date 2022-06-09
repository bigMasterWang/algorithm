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

		// ѧ���Ķ���, cmp����С�ڷ���true�����ڷ���false
		// 1. lambda��д��
		// 2. intתstring
		sort(numsStr.begin(), numsStr.end(), cmp);
		string res = "";
		for (string s : numsStr)
			res += s;
		return res;
	}
};