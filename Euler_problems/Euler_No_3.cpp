#include<bits/stdc++.h>
using namespace std;
int main(){
    long int target = 600851475143;
    long int large = 0;
    for (long int i = 3; i * i <= target; i += 2) {
    while (target % i == 0) {
        large = max(large, i);  // Update the largest factor
        target /= i;           // Reduce the target
    }
}
     // If the remaining target is greater than 2, it is the largest prime factor
    if (target > 2) {
        large = max(large, target);
    }
    cout << large;
    return 0;
}




