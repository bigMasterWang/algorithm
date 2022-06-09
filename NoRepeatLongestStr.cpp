#include<string>
#include<vector>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();
		vector<int> dp(s.size(), 1);
		int equal_index = 0, res = 0;
		for (int i = 1; i < s.size(); i++)
		{
			equal_index = 0;
			for (int j = i - dp[i - 1]; j < i; j++)
			{
				if (s[j] == s[i])
					equal_index = j;
			}
			if (equal_index)
				dp[i] = i - equal_index;
			else
				dp[i] = dp[i - 1] + 1;

			res = res > dp[i] ? res : dp[i];
		}
		return res;
	}
};