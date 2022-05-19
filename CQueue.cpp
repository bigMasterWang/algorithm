#include<stack>

class CQueue {
private:
	std::stack<int> insertStack;
	std::stack<int> deleteStack;
public:
	CQueue() {

	}

	void appendTail(int value) {
		insertStack.push(value);
	}

	int deleteHead() {
		if (deleteStack.empty())
		{
			while (not insertStack.empty())
			{
				deleteStack.push(insertStack.top());
				insertStack.pop();
			}
		}
		if (deleteStack.empty())
			return -1;
		int res = deleteStack.top();
		deleteStack.pop();
		return res;
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */