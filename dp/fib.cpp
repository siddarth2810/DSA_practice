#include <bits/stdc++.h>
using namespace std;

int fib(int num, vector<int> &dp){
	if(num <=1 ) return num;
	if (dp[num] != -1)
		return dp[num]; 
	return dp[num] = fib(num-1, dp) + fib(num-2, dp);
}

int main (){
	int n;
	cin >> n;
	vector<int> dp(n+1, -1);
        cout << fib(n, dp);
	return 0;
}



