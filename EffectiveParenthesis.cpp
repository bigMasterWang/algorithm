#include<string>
#include<stack>
using namespace std;



class Solution {
public:
	bool isValid(string s) {
		stack<char> parenthesisStack;
		for (char c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				parenthesisStack.push(c);
			if (c == ')')
			{
				if (parenthesisStack.empty())
					return false;
				if (parenthesisStack.top() == '(')
					parenthesisStack.pop();
				else
					parenthesisStack.push(c);
			}
			if (c == ']')
			{
				if (parenthesisStack.empty())
					return false;
				if (parenthesisStack.top() == '[')
					parenthesisStack.pop();
				else
					parenthesisStack.push(c);
			}
			if (c == '}')
			{
				if (parenthesisStack.empty())
					return false;
				if (parenthesisStack.top() == '{')
					parenthesisStack.pop();
				else
					parenthesisStack.push(c);
			}
		}
		return parenthesisStack.empty();
	}
};