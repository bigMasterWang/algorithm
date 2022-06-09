#include<vector>
using namespace std;


class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {

		int res = 0;
		for (int i : nums)
			res ^= i;

		// res��a^b�Ľ���� �ҵ���һ����Ϊ0��λ
		int flag = 1;
		while ((res & flag) == 0)
			flag <<= 1;
		int a = 0, b = 0;
		for (int i : nums)
		{
			if ((i ^ flag) == 0)
				a ^= i;
			else
				b ^= i;
		}
		return { a, b };
	}
};