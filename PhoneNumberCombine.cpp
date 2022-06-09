#include<vector>
#include<string>
#include<map>
using namespace std;


class Solution {
private:
	vector<string>res;
	map<char, string> numberMap;
	void search(string path, string& source, int index)
	{
		if (index >= source.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < numberMap[source[index]].size(); i++)
		{
			search(path + numberMap[source[index]][i], source, index + 1);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		if (digits == "")
			return res;
		numberMap['2'] = "abc";
		numberMap['3'] = "def";
		numberMap['4'] = "ghi";
		numberMap['5'] = "jkl";
		numberMap['6'] = "mno";
		numberMap['7'] = "pqrs";
		numberMap['8'] = "tuv";
		numberMap['9'] = "wxyz";
		search("", digits, 0);
		return res;
	}
};