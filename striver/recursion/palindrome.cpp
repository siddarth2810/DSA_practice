#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(string &s, int i){
	int n = s.length();
	if(i >= n/2)return true;

	if(s[i] != s[n-i-1]){
		return false;
	}
	return check_palindrome(s, i+1);
}

int main () {
	string s = "madam";
	cout << check_palindrome(s, 0);
	return 0;
}

