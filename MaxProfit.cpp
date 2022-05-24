#include<vector>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		vector<int>dp(prices.size(), 0);
		dp[0] = 0;
		int _todayMoney = 0, max = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			_todayMoney = prices[i] - prices[i - 1];
			if (dp[i - 1] + _todayMoney > _todayMoney)
				dp[i] = dp[i - 1] + _todayMoney;
			else
				dp[i] = _todayMoney;
			max = max < dp[i] ? dp[i] : max;
		}
		return max;
	}
};