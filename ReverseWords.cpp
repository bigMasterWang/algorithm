#include<string>
using namespace std;

/*
���룺s = "Let's take LeetCode contest"
�����"s'teL ekat edoCteeL tsetnoc"

"   Let'stakeLeetCodecontest"
*/


class Solution {
public:
	string reverseWords(string s) {
		int l = 0, r = 0;
		char ex;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
				continue;
			r = i - 1;
			for (l; l <= r; l++)
			{
				ex = s[l];
				s[l] = s[r];
				s[r] = ex;
				r--;
			}
			// �����ո���ô��
			l = i + 1;
		}
		r = s.size() - 1;
		for (l; l <= r; l++)
		{
			ex = s[l];
			s[l] = s[r];
			s[r] = ex;
			r--;
		}
		return s;
	}
};