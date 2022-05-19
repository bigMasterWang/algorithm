#include<stack>
#include<climits>

class MinStack {
private:
	std::stack<int> valueStack;
	std::stack<int> minStack;
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		valueStack.push(x);
		if (minStack.empty())
			minStack.push(x);
		else
			minStack.push(minStack.top() < x ? minStack.top() : x);
	}

	void pop() {
		valueStack.pop();
		minStack.pop();
	}

	int top() {
		return valueStack.top();
	}

	int min() {
		return minStack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */