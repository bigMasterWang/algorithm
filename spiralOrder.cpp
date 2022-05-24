#include<vector>
using namespace std;
//
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		vector<int>res;
//		// 判断特殊情况
//		if (matrix.size() == 0)
//			return res;
//
//		// 朝向， 1: 右， 2下， 3左， 4上
//		bool moveDir = 1;
//		int _h = matrix[0].size(), _v = matrix.size();
//		int matrixSize = _v * _h;
//		int mark = -1;
//		int curI = 0, curJ = 0;
//		res.push_back(matrix[curI][curJ]);
//		for (int i = 0; i < matrixSize; i++)
//		{
//			if (moveDir == 1)
//			{
//				if (curJ + 1 < _h && matrix[curI][curJ + 1] != mark)
//				{
//					res.push_back(matrix[curI][++curJ]);
//					matrix[curI][curJ] = -1;
//				}
//				else if (curI + 1 < _v && matrix[curI + 1][curJ] != mark)
//				{
//					res.push_back(matrix[++curI][curJ]);
//					matrix[curI][curJ] = -1;
//					moveDir = 2;
//				}
//				else
//					break;
//			}
//			else if (moveDir == 2)
//			{
//				if (curI + 1 < _v && matrix[curI + 1][curJ] != mark)
//				{
//					res.push_back(matrix[++curI][curJ]);
//					matrix[curI][curJ] = -1;
//				}
//				else if (curJ - 1 >= 0 && matrix[curI][curJ - 1] != mark)
//				{
//					res.push_back(matrix[curI][--curJ]);
//					matrix[curI][curJ] = -1;
//					moveDir = 3;
//				}
//				else
//					break;
//			}
//			else if (moveDir == 3)
//			{
//				if (curJ - 1 >= 0 && matrix[curI][curJ - 1] != mark)
//				{
//					res.push_back(matrix[curI][--curJ]);
//					matrix[curI][curJ] = -1;
//				}
//				else if (curI - 1 >= 0 && matrix[curI - 1][curJ] != mark)
//				{
//					res.push_back(matrix[--curI][curJ]);
//					matrix[curI][curJ] = -1;
//					moveDir = 4;
//				}
//				else
//					break;
//			}
//			else if (moveDir == 4)
//			{
//				if (curI - 1 >= 0 && matrix[curI - 1][curJ] != mark)
//				{
//					res.push_back(matrix[--curI][curJ]);
//					matrix[curI][curJ] = -1;
//				}
//				else if (curJ + 1 < _h && matrix[curI][curJ + 1] != mark)
//				{
//					res.push_back(matrix[curI][++curJ]);
//					matrix[curI][curJ] = -1;
//					moveDir = 1;
//				}
//				else
//					break;
//			}
//
//		}
//
//		return res;
//	}
//};

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>res;
		if (matrix.size() == 0)
			return res;
		int l = 0, t = 0, r = matrix[0].size() - 1, b = matrix.size() - 1;
		while (l <= r || t <= b)
		{
			for (int i = l; i <= r; i++)
				res.push_back(matrix[t][i]);
			t++;
			if (l > r || t > b)
				break;
			for (int i = t; i <= b; i++)
				res.push_back(matrix[i][r]);
			if (l > r || t > b)
				break;
			r--;
			for (int i = r; i >= l; i--)
				res.push_back(matrix[b][i]);
			if (l > r || t > b)
				break;
			b--;
			for (int i = b; i >= t; i--)
				res.push_back(matrix[i][l]);
			l++;
			if (l > r || t > b)
				break;
		}
		return res;
	}
};