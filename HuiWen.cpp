using namespace std;
#include<vector>
#include<string>
class Solution {
public:
	string longestPalindrome(string s) {
		int _l = s.length();
		vector<vector<int>> dp(_l, vector<int>(_l));

		for (int i = 0; i < _l; i++)
			dp[i][i] = 1;

		int max_len = 1, _start_index = 0;
		for (int i = 0; i < _l; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (s[i] != s[j])
					dp[i][j] = 0;
				else
				{
					if (j + 1 == i)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i - 1][j + 1];
				}
				if (dp[i][j] && (i - j + 1) > max_len)
				{
					max_len = i - j + 1;
					_start_index = j;
				}
			}
		}
		return s.substr(_start_index, max_len);
	}
};