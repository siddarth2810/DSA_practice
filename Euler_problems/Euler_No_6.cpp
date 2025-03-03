#include <bits/stdc++.h>
using namespace std;

int sum_of_natural_numbers(int n){
    return n*(n+1)/2;
}

int sum_of_squares(int n){
    return n*(2*n+1)*(n+1)/6;
}

int main (){
    int s1 = sum_of_squares(100);
    int s2 =  sum_of_natural_numbers(100);
    cout << s2*s2 - s1;
    return 0;
}
