#include<vector>
using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>> target(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				target[j][n - i] = matrix[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = target[i][j];
			}
		}
	}
};