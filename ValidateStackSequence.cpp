#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> realStack;
		int outIndex = 0;
		for (int i = 0; i < pushed.size(); i++)
		{
			realStack.push(pushed[i]);
			if (realStack.top() == popped[outIndex] && realStack.size() != 0)
			{
				realStack.pop();
				outIndex++;
			}
		}
		return realStack.empty();
	}
};