#include<vector>
#include<math.h>
using namespace std;


class Solution {
public:
	vector<int> grayCode(int n) {
		if (n <= 1)
			return vector<int>(n);
		vector<int> res;
		for (int i = 0; i < pow(2, n - 1) - 1; i++)
			res.push_back(i);

		for (int i = pow(2, n) - 1; i >= pow(2, n - 1) - 1; i--)
			res.push_back(i);
		return res;
	}
};