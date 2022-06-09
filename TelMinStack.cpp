#include<stack>
using namespace std;

class MinStack {
private:
	stack<int>valueStack;
	stack<int>minStack;
public:
	MinStack() {

	}

	void push(int val) {
		valueStack.push(val);
		if (minStack.empty())
			minStack.push(val);
		else
			minStack.push(minStack.top() < val ? minStack.top() : val);
	}

	void pop() {
		minStack.pop();
		valueStack.pop();
	}

	int top() {
		return valueStack.top();
	}

	int getMin() {
		return minStack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */