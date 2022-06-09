#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		priority_queue<int> kNumbers;

		for (int i = 0; i < arr.size(); i++)
		{
			if (kNumbers.size() < k)
			{
				kNumbers.push(arr[i]);
				continue;
			}
			if (kNumbers.top() > arr[i])
			{
				kNumbers.pop();
				kNumbers.push(arr[i]);
			}
		}

		vector<int>res;
		for (int i = 0; i < kNumbers.size(); i++)
		{
			res.push_back(kNumbers.top());
			kNumbers.pop();
		}
		return res;
	}
};