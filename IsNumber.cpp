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
		// ȥ����ͷ�ͽ�β�Ŀո�
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);


		Status state = DEFAULT;
		/*
		+-  : sign: ���������
		����: int : ���Ը� ���� | . | e | E
		С��: float: ���Ը����� | e | e
		e | E : exp: ���������
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
				// ǰ��������һ������
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