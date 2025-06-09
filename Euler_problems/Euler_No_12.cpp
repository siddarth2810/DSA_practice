#include <bits/stdc++.h>
using namespace std;

int countDivisors(long long number) {
  int count = 1;
  for (long long i = 2; i * i <= number; i++) {
    int power = 0;
    while (number % i == 0) {
      power++;
      number /= i;
    }
    count *= (power + 1);
  }
  // say we have 17, we need count (1+1)
  if (number > 1)
    count *= 2;
  return count;
}

int main() {
  // generate numbers
  int n = 1;

  while (true) {
    long long triangle;
    if (n % 2 == 0)
      triangle = (n / 2) * (n + 1);
    else
      triangle = n * ((n + 1) / 2);

    //rather than giving number itself, divide it 
    int divisors = countDivisors(n % 2 == 0 ? (n / 2) : n) *
                   countDivisors(n % 2 == 0 ? (n + 1) : ((n + 1) / 2));

    if (divisors > 500) {
      cout << triangle << endl;
      break;
    }
    n++;
  }

  return 0;
}
