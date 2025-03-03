#include<bits/stdc++.h>
using namespace std;
//brute force approach
int brute_force(){
    int f1 = 1;
    int f2 = 2;
    int f3 = 0;
    int sum = 2;
    while (f3 < 4000000){
        f3 = f1 + f2;
        if (f3 % 2 == 0){
            sum += f3;
        }
        f1= f2;
        f2 = f3;
    }
    cout << sum;
    return 0;
}
//optmized calculate every thrid
int optmized(){
    int even_f1 = 2;
    int even_f2 = 8;
    int sum = even_f1;
    while(even_f2 < 4000000){
        sum += even_f2;
        int next_even= 4*even_f2+even_f1;
        even_f1 = even_f2;
        even_f2 = next_even;
    }
    cout << sum;
    return 0;
}
int main(){
    brute_force();
    cout << endl;
    optmized();
    return 0;
}



