#include<vector>
using namespace std;



class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int _v = matrix.size();
		int _h = matrix[0].size();

		int _start_v = -1, _start_h = -1;

		for (int i = 0; i < _h; i++)
		{
			if (matrix[_v - 1][i] > target)
			{
				_start_h = i;
				break;
			}
			if (matrix[_v - 1][i] == target)
				return true;
		}
		if (_start_h == -1)
			return false;


		for (int i = 0; i < _v; i++)
		{
			if (matrix[i][_h - 1] > target)
			{
				_start_v = i;
				break;
			}
			if (matrix[i][_h - 1] == target)
				return true;
		}
		if (_start_v == -1)
			return false;



		for (int i = _start_v; i < _v; i++)
		{
			for (int j = _start_h; j < _h; j++)
			{
				if (matrix[i][j] == target)
					return true;
			}
		}
		return false;
	}
};