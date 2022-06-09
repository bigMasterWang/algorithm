#include<string>
using namespace std;

/*
ÊäÈë: "the sky is blue"
Êä³ö: "blue is sky the"
*/

class Solution {
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int left = 0, right = 0;
		char ex;
		for (right; right < s.size(); right++)
		{
			if (s[right] != ' ')
				continue;
			int exRight = right;
			while (left <= exRight)
			{
				ex = s[left];
				s[left] = s[exRight];
				s[exRight] = ex;
				left++;
				exRight--;
			}
			left = right + 1;
		}
		int exRight = right;
		while (left <= exRight)
		{
			ex = s[left];
			s[left] = s[exRight];
			s[exRight] = ex;
			left++;
			exRight--;
		}
		return s;
	}
};