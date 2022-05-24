#include<vector>
#include<climits>
using namespace std;
/*

	1 2 3
	8 9 4
	7 6 5
*/
//
//class Solution {
//public:
//	vector<vector<int>> generateMatrix(int n) {
//		int mark = INT_MIN;
//		vector<vector<int>> matrix(n, vector<int>(n, mark));
//		// 方向， 1向右，2向下，3向左，4向上
//		int forward = 1;
//		int curValue = 1, i = 0, j = 0;
//		matrix[i][j] = curValue;
//		curValue++;
//		if (n == 1)
//			return matrix;
//		for (int t = 0; t < n * n; t++)
//		{
//			if (forward == 1)
//			{
//				if (j + 1 < n && matrix[i][j + 1] == mark)
//					matrix[i][++j] = curValue++;
//				else if (i + 1 < n && matrix[i + 1][j] == mark)
//				{
//					matrix[++i][j] = curValue++;
//					forward = 2;
//				}
//				else
//					break;
//			}
//			else if (forward == 2)
//			{
//				if (i + 1 < n && matrix[i + 1][j] == mark)
//					matrix[++i][j] = curValue++;
//				else if (j - 1 >= 0 && matrix[i][j - 1] == mark)
//				{
//					matrix[i][--j] = curValue++;
//					forward = 3;
//				}
//				else
//					break;
//			}
//			else if (forward == 3)
//			{
//				if (j - 1 >= 0 && matrix[i][j - 1] == mark)
//					matrix[i][--j] = curValue++;
//				else if (i - 1 >= 0 && matrix[i - 1][j] == mark)
//				{
//					matrix[--i][j] = curValue++;
//					forward = 4;
//				}
//				else
//					break;
//			}
//			else if (forward == 4)
//			{
//				if (i - 1 >= 0 && matrix[i - 1][j] == mark)
//					matrix[--i][j] = curValue++;
//				else if (j + 1 < n && matrix[i][j + 1] == mark)
//				{
//					matrix[i][++j] = curValue++;
//					forward = 1;
//				}
//				else
//					break;
//			}
//		}
//
//		return matrix;
//	}
//};


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int l = 0, t = 0, r = n - 1, b = n - 1, value = 1;
		vector<vector<int>> res(n, vector<int>(n, 0));
		while (value <= n)
		{
			for (int i = l; i <= r; i++)
				res[t][i] = value++;
			t++;
			for (int i = t; i <= b; i++)
				res[i][r] = value++;
			r--;
			for (int i = r; i >= l; i--)
				res[b][i] = value++;
			b--;
			for (int i = b; i >= t; i--)
				res[i][b] = value++;
			l++;
		}
		return res;
	}
};