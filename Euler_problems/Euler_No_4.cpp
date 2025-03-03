#include<bits/stdc++.h>
#include <string>
using namespace std;
//largest palindrome using two digits is 9009 = 91X99, then three digits ?
bool palindrome(int n){
    string s = to_string(n); // Convert the number to a string.
    string rev = s;         // Make a copy of the string.
    reverse(rev.begin(), rev.end()); // Reverse the copied string.
    return s == rev;
}

//optmized
int solution(){
    int r = 0;
    for(int p=990; p>99; p-=11){
        for(int q=999; q>99; q--){
            int t = p*q;
            if(r<t && palindrome(t)){
                r =t;
                break;
            }
            else if(r<t){
                break;
            }
        }
    }
    cout << r;
    return r;
}




//brute force
int main(){
    int r = 0;
    //our condition p*q =11(9091a+910b+100c) <= 999*999
    //990 is largest multiple of 11
    for(int s,q, p=999; p>=100; p--){
        if(p%11== 0){
            s=1;
            q=999;
        }else {
            s=11;
            q=990;
        }
        for(int k=0; q>99; q-=s){
            int t = p*q;
            if(r<t && palindrome(t)){
                r=t;
                break;
            }
        }
    }
    cout << r;
    return r;
}

