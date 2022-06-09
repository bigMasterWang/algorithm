#include<vector>
using namespace std;

class Solution {
public:
	int lastRemaining(int n, int m) {
		vector<bool>dp(n, false);

		int i = 0, number = 0;
		while (true)
		{
			for (int j = 0; j < m; j++)
			{
				i += 1;
				if (dp[i])
					j--;
			}
			dp[i] = true;
			number++;
			if (number == n - 1)
				break;
		}

		for (int i = 0; i < n; i++)
			if (!dp[i])
				return i;
		return 0;
	}
};