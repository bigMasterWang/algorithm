#include<vector>
using namespace std;

/*
1 2 3 4 5
5 / 2 = 2.5

*/
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>res;
		int left, right;
		for (int i = 2; i <= target; i++)
		{
			if (i % 2 == 1)
			{
				// 奇数的话，必须target / i为整数
				if (target % i != 0)
					continue;
				int number = (i - 1) / 2;
				if (i - number < 0 || i + number > target)
					continue;
				left = i - number;
				right = i + number;

			}
			else
			{
				// 偶数个， target % i 必须不为0
				if (target % i == 0)
					continue;
				right = i / 2;
				left = right - 1;
				if (i - left < 0 || i + right > target)
					continue;
				left = i - left;
				right = i + right;
			}
			vector<int> a;
			for (int i = left; i <= right; i++)
				a.push_back(i);
			res.push_back(a);
		}
		return res;
	}
};