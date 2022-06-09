#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0)
			return {};
		reverse(digits.begin(), digits.end());

		int add = 1;
		for (int i = 0; i < digits.size(); i++)
		{
			digits[i] += add;
			digits[i] %= 10;
			add /= 10;
		}
		if (add != 0)
			digits.push_back(add);

		reverse(digits.begin(), digits.end());
		return digits;
	}
};