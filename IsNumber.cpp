#include<string>
using namespace std;


class Solution {
private:
	bool isNumber(char x)
	{
		return (x - '0' >= 0 && x - '0' <= 9);
	}
	enum Status
	{
		DEFAULT, SIGN, INT, FLOAT, EXP
	};
public:
	bool isNumber(string s) {
		// 去掉开头和结尾的空格
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);


		Status state = DEFAULT;
		/*
		+-  : sign: 必须跟数字
		整数: int : 可以跟 数字 | . | e | E
		小数: float: 可以跟数字 | e | e
		e | E : exp: 必须根整数
		*/
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				if (state == SIGN)
					return false;
				if (i + 1 >= s.size() || !isNumber(s[i + 1]))
					return false;
				state = SIGN;
			}
			else if (s[i] == '.')
			{
				// 前后至少有一个数字
				if (state == INT)
					state = FLOAT;
				else if (i + 1 < s.size() && isNumber(s[i]))
					state = FLOAT;
				else
					return false;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				if (!(state == INT || state == FLOAT))
					return false;
				state = EXP;
			}
			else if (isNumber(s[i]))
			{
				if (state == SIGN || state == DEFAULT || state == EXP)
					state = INT;
			}
			else
				return false;
		}
		if (state == INT || state == FLOAT)
			return true;
		return false;
	}
};