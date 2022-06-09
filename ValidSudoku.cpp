#include<vector>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int rows[9][9]{ 0 };
		int cols[9][9]{ 0 };
		int rowCol[3][3][9] = { 0 };
		int n = 0;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				n = board[i][j] - '0' - 1;
				if (rows[i][n] || cols[j][n] || rowCol[i / 3][j / 3][n])
					return false;
				rows[i][n] += 1;
				cols[j][n] += 1;
				rowCol[i / 3][j / 3][n] += 1;
			}
		}
		return true;
	}
};