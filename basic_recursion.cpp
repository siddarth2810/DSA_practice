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

//print n to 1
int NToOne(int i, int n){
    if(i<1)
        return 1;
    else{
        cout << i << endl;
        return NToOne(i-1, n);
    }
    
}

//print 1 to n using backtracking
int one_to_N_backtracking(int i, int n){
    if(i<1)
        return 1;
    one_to_N_backtracking(i-1,n);
    cout << i << endl;
    return 0;        
}


int main () {
// int result = sum(5);
// int first = oneToN(1,5);
// int non_linear = NToOne(5,5);
// int nope = one_to_N_backtracking(5,5);

return 0;
}
