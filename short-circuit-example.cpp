#include <bits/stdc++.h>
using namespace std;

//implement queue with two stacks 


class Queue {
	public:
	vector<int> st1;
	vector<int> st2;

	void enqueue(int itemValue) {
		if(st1.empty() && st2.empty()){
			st1.push_back(itemValue);
		} else if (st2.empty() && !st1.empty()){
			st1.push_back(itemValue);
			st2.push_back(itemValue);
		} else {
			st2.pop_back();
			st1.push_back(itemValue);
			st2.push_back(itemValue);
		}

	}

	void dequeue() {
	}
};

int main() {
	vector<int> arr = {1,2,3,4,5,6};
    return 0;
}

