#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

/*
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
*/


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> wordsMap;
		string s = "";
		for (int i = 0; i < strs.size(); i++)
		{
			s = strs[i];
			sort(s.begin(), s.end());
			if (wordsMap.find(s) != wordsMap.end())
				wordsMap[s].push_back(strs[i]);
			else
				wordsMap[s] = {};
		}
		vector<vector<string>> res;
		for (auto it : wordsMap)
			res.push_back(it.second);
		return res;
	}
};