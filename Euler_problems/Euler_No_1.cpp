#include<bits/stdc++.h>
using namespace std;

int sumof(int n, int limit){
    int k = (limit - 1) / n;  
    return n * k * (k + 1) / 2;  
}

//get sum of multiples of 3 and 5 under 1000
int main(){
    int limit = 1000;
    int sum = sumof(3,limit) + sumof(5,limit) - sumof(15,limit);
    cout << sum;
    return sum;
}

