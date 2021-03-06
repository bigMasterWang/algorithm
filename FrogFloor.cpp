#include<vector>
using namespace std;

// 最终结果对 1000000007 取余
class Solution {
public:
	int numWays(int n) {
		if (n <= 1)
			return 1;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		return dp[n];
	}
};