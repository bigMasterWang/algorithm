#include<vector>
using namespace std;


class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> pathMatrix(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
			pathMatrix[i][0] = 1;
		for (int i = 0; i < n; i++)
			pathMatrix[0][i] = 1;

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
				pathMatrix[i][j] = pathMatrix[i - 1][j] + pathMatrix[i][j - 1];
		}
		return pathMatrix[m - 1][n - 1];
	}
};