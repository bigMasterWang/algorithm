#include<string>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		bool flag = false;
		for (int i = 0; i < haystack.size(); i++)
		{
			if (haystack[i] == needle[0])
			{
				// Ñ­»·ÕÒ
				flag = true;
				for (int j = 0; i < needle.size(); j++)
				{
					if (haystack[i + j] != needle[j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					return i;

			}
		}
		return -1;
	}
};