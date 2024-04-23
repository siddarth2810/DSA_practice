// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

//sum of first n natural numbers 
int sum(int n){
  if ( n==1)
    return 1;
  else
    return n+ sum(n-1);
}


//print till n numbers linearly
int oneToN(int i, int n) {
  if (i==n){
    cout << i << endl;
    return n;
        }
  else {
    cout << i << endl;
    return oneToN(i+1, n);
        }
}
    
    
int main () {
// int result = sum(5);
// int first = oneToN(1,5);
return 0;
}
