#include<bits/stdc++.h>
using namespace std;
// write a function that gives nth fib number

// 0 is 0th fib no
// 1 is 1th fib no
int fib(int n){
	if(n <= 1){
		return n;
	}
	int last = fib(n-1);
	int slast = fib(n-2);
	return last + slast;
}

int foo(int n){
	int f1 = 0;
	int f2 = 1;
	int f3;

	for(int i=2; i<n; i++){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	return f3;
}

int main () {
	cout << foo(5);
	cout << endl;
	cout << fib(3);
	return 0;
}
