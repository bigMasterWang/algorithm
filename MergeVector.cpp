#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		auto cmp = [&](vector<int> a, vector<int> b) {
			return a[0] < b[0];
		};
		sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>>res;
		int preStart = intervals[0][0], preEnd = intervals[0][1];

		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] <= preEnd)
			{
				preEnd = intervals[i][1] > preEnd ? intervals[i][1] : preEnd;
			}
			else
			{
				res.push_back({ preStart, preEnd });
				preStart = intervals[i][0];
				preEnd = intervals[i][1];
			}
		}
		res.push_back({ preStart, preEnd });
		return res;
	}
};