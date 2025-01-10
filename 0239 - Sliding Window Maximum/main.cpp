#include <iostream>
#include <vector>
#include <deque>

using std::vector, std::cout, std::endl, std::deque;

class Monotonic_Queue {
	deque<int> mqueue; // max at the front, using deque as it has pop_front()
public:
	int max() {
		return mqueue.front();
	}
	void pop(int n) {
		if (n==mqueue.front())
			mqueue.pop_front();
	}
	void push(int n) {
		while (!mqueue.empty() && mqueue.back()<n) {
			mqueue.pop_back();
		}
		mqueue.push_back(n);
	}
	void print() {
		for (int i=0; i<mqueue.size(); i++) {
			cout << mqueue[i] << " ";
		}
		cout << endl;
	}
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> output = {};
	Monotonic_Queue mqueue;
	for (int i=0; i<k-1; i++) { // initial window expansion
		mqueue.push(nums[i]);
		mqueue.print();
	}
	for (int i=k-1; i<nums.size(); i++) {
		mqueue.push(nums[i]);
		mqueue.print();
		output.push_back(mqueue.max());
		mqueue.pop(nums[i-k+1]);
	}
	return output;
}

int main() {
	vector<int> nums = {1, -1};
	for (int i: maxSlidingWindow(nums, 1)) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

/**
	 Couldn't think of a great solution for this one off the bat
	 Searching online for this kind of problem, came across the concept of a monotonic queue/stack.
	 Don't understand the concept intuitively yet, but get the general gist.
	 Not competely confident about this program, despite it scoring well and working.
	 A bit of futzing around with loop indexes and the like.
 **/
