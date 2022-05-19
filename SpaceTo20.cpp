#include <string>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string res = "";
		for (char x : s)
		{
			if (x == ' ')
				res += "%20";
			else
				res += x;
		}
		return res;
	}
};