#include<vector>
using namespace std;


class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int l = a.size();
		int* left = new int[l], * right = new int[l];
		vector<int>res(l);
		if (a.size() == 1)
			return { 0 };
		if (a.size() == 0)
			return {};
		left[0] = 1, left[1] = a[0];
		right[l - 1] = 1, right[l - 2] = a[l - 1];
		for (int i = 2; i < l; i++)
		{
			left[i] = left[i - 1] * a[i - 1];
			right[l - i - 1] = right[l - i] * a[l - i];
		}
		for (int i = 0; i < l; i++)
		{
			res[i] = left[i] * right[i];
		}
		return res;
	}
};