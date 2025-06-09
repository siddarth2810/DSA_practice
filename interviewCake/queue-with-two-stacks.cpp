#include<bits/stdc++.h>
using namespace std;

class Q {
	public:
		vector<int> in;
		vector<int> out;

	void enQ(int itemVal){
		in.push_back(itemVal);
	}

	void deQ(){
		shiftall();
		if(out.empty()){
			cout << "q is empty" << endl;
		}
		out.pop_back();
	}

	void peek(){
		if(out.empty()){
			cout << "q is empty" << endl;
		}
		cout << out.back() << endl;

	}
	void shiftall(){
		if(out.empty()){
		while(!in.empty()){
			int val = in.back();
			out.push_back(val);
			in.pop_back();
		}
		}
	}

	void display(){
		for(auto it: out) {
			cout << it << " ";
		}
		cout << endl;
	}
};

int main () {
	Q que;
	que.enQ(1);
	que.enQ(2);
	que.enQ(3);
	que.enQ(4);
	que.deQ();
	que.deQ();
	que.peek();
	que.display();

	return 0;
}

