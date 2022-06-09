#include<string>
#include<vector>
using namespace std;

/*
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();
		vector<int> dp(s.size(), 1);
		for (int i = 1; i < s.size(); i++)
		{
			for (int j = i - dp[i - 1]; j < i; j++)
			{
				if (s[i] == s[j])
					dp[i] = dp[i - 1] + 1;
			}
		}
		return dp[s.size() - 1];
	}
};