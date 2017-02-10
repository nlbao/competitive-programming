typedef pair<int, int> pii;
typedef pair<int, int> TimeValuePair;
typedef pair<int, int> ValueTimePair;


pii reversePair(pii p) {
	return pii(p.second, p.first);
}


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        currentTime = 0;
    }

    void push(int x) {
        heapByTime.insert(TimeValuePair(currentTime, x));
		heapByValue.insert(ValueTimePair(x, currentTime));
		++currentTime;
    }

    void pop() {
        TimeValuePair topElement = *heapByTime.begin();
		heapByTime.erase(topElement);
		heapByValue.erase(reversePair(topElement));
    }

    int top() {
        return heapByTime.begin()->second;
    }

    int getMin() {
        return heapByValue.begin()->first;
    }

private:
	int currentTime;
	set<TimeValuePair, greater<pii>> heapByTime;
	set<ValueTimePair> heapByValue;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */