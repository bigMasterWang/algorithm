#include<vector>
#include<string>
using namespace std;


class Solution {
private:
	string word = "";
	bool dfs(vector<vector<char>>& board, int i, int j, int k)
	{
		if (i < 0 || i == board.size() || j < 0 || j == board[i].size() || word[k] != board[i][j])
			return false;
		char save = board[i][j];
		board[i][j] = '\0';
		bool res =
			dfs(board, i - 1, j, k + 1) ||
			dfs(board, i + 1, j, k + 1) ||
			dfs(board, i, j - 1, k + 1) ||
			dfs(board, i, j + 1, k + 1);
		board[i][j] = save;
		return res;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		this->word = word;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				bool res = dfs(board, i, j, 0);
				if (res)
					return res;
			}
		}
		return false;
	}
};