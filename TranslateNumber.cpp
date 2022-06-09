/*
0: a,, 25: z
һ�����ֶ����ͬ�ķ���
����: 12258
���: 5
����: 12258��5�ֲ�ͬ�ķ��룬�ֱ���"bccfi", "bwfi", "bczi", "mcfi"��"mzi"
*/
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(int num) {
		if (num > 10 && num <= 25)
			return 2;
		if (num < 100)
			return 1;
		string s = "";
		while (num)
		{
			s += (num % 10) + '0';
			num /= 10;
		}
		reverse(s.begin(), s.end());
		vector<int>dp(s.size(), 1);
		// ���ж�ǰ��λ
		if (10 < (s[0] - '0') * 10 + (s[1] - '0') <= 25)
			dp[1] = 2;
		for (int i = 2; i < s.size(); i++)
		{
			if (10 < (s[i - 1] - '0') * 10 + (s[i] - '0') <= 25)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1];
		}
		return dp[s.size() - 1];
	}
};