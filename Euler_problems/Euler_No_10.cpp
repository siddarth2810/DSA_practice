#include <bits/stdc++.h>
using namespace std;

bool isPrime(long number) {
  if (number < 2)
    return false;

  for (long i = 2; i <= sqrt(number); i++) {
    if (number % i == 0)
      return false; 
  }
  return true;
}

int main() {
  long sum = 2;
  for (long i = 3; i < 2000000; i++) {
    if (!isPrime(i)) //always do error handling first
      continue;
    sum += i; //sucess path
  }
  cout << sum << endl;

  return 0;
}

