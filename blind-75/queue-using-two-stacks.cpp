#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    vector<int> in;
    vector<int> out;
    MyQueue() {
    }

    void push(int x) {
        in.push_back(x);
    }

    int pop() {
        //or can peek and return front
        if(out.empty()){
            while(!in.empty()){
                out.push_back(in.back());
                in.pop_back();
            }
        }
        if (!out.empty()){
            int front = out.back();
            out.pop_back();
            return front;
        }
        return -1;
    }

    int peek() {
        if(out.empty()){
            while(!in.empty()){
                out.push_back(in.back());
                in.pop_back();
            }
        }
        if (!out.empty()){
            return out.back();
        }
        return -1;
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};


int main() {
  MyQueue *obj = new MyQueue();
  obj->push(19);
  obj->push(13);
  cout << "Pop: " << obj->pop() << endl;  // 19
  cout << "Peek: " << obj->peek() << endl; // 13
  cout << "Empty: " << obj->empty() << endl; // false
  obj->pop(); // removes 13
  cout << "Empty after second pop: " << obj->empty() << endl; // true
  return 0;
}


