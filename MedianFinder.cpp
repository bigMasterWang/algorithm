#include<queue>
using namespace std;


class MedianFinder {
private:
	priority_queue<int> big;
	priority_queue<int> small;
	int counter;
public:
	/** initialize your data structure here. */
	MedianFinder() {
		counter = 0;
	}

	void addNum(int num) {
		if (counter % 2 == 1)
		{
			big.push(num);
			small.push(-big.top());
			big.pop();
		}
		else
		{
			small.push(-num);
			big.push(-small.top());
			small.pop();
		}
		counter++;
	}

	double findMedian() {
		if (counter % 2 == 1)
			return big.top();
		return ((double)(-small.top() + big.top())) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */