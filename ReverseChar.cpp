#include<vector>
using namespace std;


class Solution {
public:
	void reverseString(vector<char>& s) {
		char ex;
		int l = 0, r = s.size() - 1;
		for (l; l <= r; l++)
		{
			ex = s[l];
			s[l] = s[r];
			s[r] = ex;
			r--;
		}
		return;
	}
};