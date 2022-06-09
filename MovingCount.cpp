#include<vector>
using namespace std;


class Solution {
private:
	int calculateNumberSum(int x)
	{
		int res = 0;
		while (x)
		{
			res += x % 10;
			x /= 10;
		}
		return res;
	}
	bool getPathValue(vector<vector<bool>>& path, int i, int j)
	{
		if (i < 0 || i >= path.size() || j < 0 || j >= path[i].size())
			return false;
		return path[i][j];
	}
	bool canReach(vector<vector<bool>>& path, int i, int j)
	{
		return
			getPathValue(path, i - 1, j) ||
			getPathValue(path, i + 1, j) ||
			getPathValue(path, i, j - 1) ||
			getPathValue(path, i, j + 1);
	}
public:
	int movingCount(int m, int n, int k) {
		int res = 0;
		vector<vector<bool>> path(m, vector<bool>(n, false));
		path[0][0] = true;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (calculateNumberSum(i) + calculateNumberSum(j) <= k && canReach(path, i, j))
				{
					res++;
					path[i][j] = true;
				}
			}
		}
		return res;
	}
};