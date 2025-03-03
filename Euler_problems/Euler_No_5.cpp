#include <bits/stdc++.h>
using namespace std;

//optmized
//LCM(4,5)=20, because 20 is the smallest number that both 4 and 5 divide evenly.
//GCD(8,12)=4 because 4 is the largest number that divides both 8 and 12.
//lcm(a,b) = a*b/gcd(a,b);
//
//we need lcm(1,2,3...20) = lcm(lcm(lcm(1,2), 3)..20)

int gcd (int a, int b){
    while(b != 0){
        int temp =b;
        b = a %b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b){
    return a*b/gcd(a, b);
}

int main (){
    long long result = 1;
    for(int i=1; i<=20; i++){
        result = lcm(result, i);
    }
    cout << result;
}


/* brute force
bool is_evenly_divisible(int n){
    for(int i=1; i<=20; i++){
        if ( n% i != 0){
            return false;
        }
    }
    return true;
}

int main (){
    int n = 20;
    while(!is_evenly_divisible(n)){
        n+=2;
    }
    cout << n;
    return 0;
}
*/



