#include<string>
#include<vector>
using namespace std;



class Solution {
private:
	vector<string>res;
	void dfs(string path, int n, int leftNumber, int rightNumber)
	{
		if (path.size() == 2 * n)
		{
			res.push_back(path);
			return;
		}
		// ±ÿ–Î «◊Û¿®∫≈
		if (leftNumber == rightNumber)
			dfs(path + '(', n, leftNumber + 1, rightNumber);
		// ±ÿ–Î «”“¿®∫≈
		else if (leftNumber == n)
			dfs(path + ')', n, leftNumber, rightNumber + 1);
		else
		{
			dfs(path + '(', n, leftNumber + 1, rightNumber);
			dfs(path + ')', n, leftNumber, rightNumber + 1);
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		dfs("", n, 0, 0);
		return res;
	}
};