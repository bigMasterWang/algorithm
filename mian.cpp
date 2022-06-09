#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;

/*
1  2  3  4
5  6  7  8
9  10 11 12
*/

/*
		if (board[i][j] != word[0])
			return false;
		board[i][j] = '\0';
		int wordIndex = 1;
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
*/
class Solution {
private:
	bool findWords(vector<vector<char>>& board, string word, int i, int j, int wordIndex)
	{
		if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size())
			return false;
		if (!board[i][j] || board[i][j] != word[wordIndex])
			return false;
		wordIndex++;
		if (wordIndex == word.size())
			return true;
		char save = board[i][j];
		board[i][j] = '\0';
		bool flag =
			findWords(board, word, i - 1, j, wordIndex) ||
			findWords(board, word, i + 1, j, wordIndex) ||
			findWords(board, word, i, j - 1, wordIndex) ||
			findWords(board, word, i, j + 1, wordIndex);
		board[i][j] = save;
		return flag;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (findWords(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<vector<char>>a;
	a.push_back({ 'A', 'B', 'C', 'E' });
	a.push_back({ 'S', 'F', 'C', 'S' });
	a.push_back({ 'A', 'D', 'E', 'E' });
	std::cout << s.exist(a, "ABCB");
}