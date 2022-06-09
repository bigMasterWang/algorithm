#include<string>
using namespace std;

/*
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
class Solution {
public:
	string countAndSay(int n) {
		auto getStr = [](string x)
		{
			int l = x.size();
			return to_string(l) + x[0];
		};
		if (n == 1)
			return "1";
		if (n == 2)
			return "11";
		string s = "11", s2;
		int preIndex = 0;
		for (int i = 0; i < n; i++)
		{
			s2 = "";
			preIndex = 0;
			for (int j = 1; j < s.size(); j++)
			{
				if (s[i] != s[i - 1])
				{
					s2 += getStr(s.substr(preIndex, i - preIndex + 1));
					preIndex = i;
				}
			}
			s2 += getStr(s.substr(preIndex, s.size() - preIndex));
			s = s2;
		}
		return s;
	}
};