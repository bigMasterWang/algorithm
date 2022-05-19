#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pre = "";
		int _index = 0;
		for (char x : strs[0])
		{
			bool isPre = true;
			for (string item : strs)
			{
				// 索引超过了长度
				if (item.size() == _index)
					return strs[0].substr(0, _index);
				if (x != item[_index])
				{
					if (_index == 0)
						return "";
					return strs[0].substr(0, _index);
				}
			}
			_index++;
		}
		return strs[0].substr(0, _index);
	}
};