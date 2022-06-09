#include<vector>
#include<string>
using namespace std;


class Solution {
private:
	bool findWords(vector<vector<char>> board, string word, int i, int j)
	{
		int wordIndex = 0;
		while (wordIndex < word.size())
		{
			//按照上下左右的顺序去做
			if (i - 1 >= 0 && board[i - 1][j] && board[i - 1][j] == word[wordIndex])
			{
				wordIndex++;
				board[i - 1][j] = '\0';
			}
			else if (j + 1 < board[i].size() && board[i][j + 1] && board[i][j + 1] == word[wordIndex])
			{
				wordIndex++;
				board[i][j + 1] = '\0';
			}
			else if (i + 1 < board.size() && board[i + 1][j] && board[i + 1][j] == word[wordIndex])
			{
				wordIndex++;
				board[i + 1][j] = '\0';
			}
			else if (j - 1 >= 0 && board[i][j - 1] && board[i][j - 1] == word[wordIndex])
			{
				wordIndex++;
				board[i][j - 1] = '\0';
			}
			else
				break;
		}
		return (wordIndex == word.size());
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (findWords(board, word, i, j))
					return true;
			}
		}
		return false;
	}
};