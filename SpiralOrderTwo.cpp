#include<vector>
using namespace std;


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int left = 0, top = 0, right = matrix[0].size(), bottom = matrix.size();

		vector<int>res;
		while (left < right && top < bottom)
		{
			for (int i = left; i <= right; i++)
				res.push_back(matrix[top][i]);
			top--;
			for (int i = top; i <= bottom; i++)
				res.push_back(matrix[i][right]);
			right--;
			for (int i = right; i >= left; i--)
				res.push_back(matrix[bottom][i]);
			bottom++;
			for (int i = bottom; i >= top; i--)
				res.push_back(matrix[i][left]);
			left++;
		}
		return res;
	}
};