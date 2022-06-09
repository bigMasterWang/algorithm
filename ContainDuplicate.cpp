#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		vector<int> record;
		for (int x : nums)
		{
			// != end�����ҵ���
			if (find(record.begin(), record.end(), x) != record.end())
				return true;
			record.push_back(x);
		}
		return false;
	}
};