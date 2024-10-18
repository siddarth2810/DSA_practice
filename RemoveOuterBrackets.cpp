#include<bits/stdc++.h>
using namespace std;

int main() {
    //remove outer parentheses from a string
    string s = "(()())(())(()(()))";
    int n = s.size();
    string ans = "";
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            count++;
            if(count > 1) {
                ans += s[i];
            }
        }
        else {
            count--;
            if(count > 0) {
                ans += s[i];
            }
        }
    }
   cout << ans << endl; 

    return 0;

}


