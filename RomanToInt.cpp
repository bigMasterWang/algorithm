#include<string>
#include<map>
using namespace std;

/*
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> romanBaseInt;
		romanBaseInt['I'] = 1;
		romanBaseInt['V'] = 5;
		romanBaseInt['X'] = 10;
		romanBaseInt['L'] = 50;
		romanBaseInt['C'] = 100;
		romanBaseInt['D'] = 500;
		romanBaseInt['M'] = 1000;
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'I')
			{
				if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
				{
					res += romanBaseInt[s[i + 1]] - romanBaseInt[s[i]];
					i += 1;
				}
				else
				{
					res += romanBaseInt[s[i]];
				}
			}
			else if (s[i] == 'X')
			{
				if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
				{
					res += romanBaseInt[s[i + 1]] - romanBaseInt[s[i]];
					i += 1;
				}
				else
				{
					res += romanBaseInt[s[i]];
				}
			}
			else if (s[i] == 'C')
			{
				if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
				{
					res += romanBaseInt[s[i + 1]] - romanBaseInt[s[i]];
					i += 1;
				}
				else
				{
					res += romanBaseInt[s[i]];
				}
			}
			else
			{
				res += romanBaseInt[s[i]];
			}
		}
		return res;
	}
};