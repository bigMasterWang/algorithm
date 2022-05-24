#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res(1 << n);
		for (int i = 0; i < res.size(); i++)
			res[i] = i >> 1 ^ i;
		return res;
	}
};

int main()
{
	Solution s;
	auto res = s.grayCode(3);
	for (int x : res)
		std::cout << x << std::endl;
}