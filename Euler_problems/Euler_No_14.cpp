#include <bits/stdc++.h>
using namespace std;


// without hasmap and vector: 0.64 s
// with hasmap and vector: 1.04 sec
int main() {
  long long longestChain = 0;
  long long startingNumber = 0;
  map<long long, long long> seenNumbers;
  for (long i = 1000000; i >= 1000000 / 2; i--) {
    long long n = i;
    long long tempChain = 0;
    vector<long long> sequence;

    while (n != 1) {
      if (seenNumbers.find(n) != seenNumbers.end()) {
        tempChain += seenNumbers[n];
        break;
      }
      sequence.push_back(n);
      if (n % 2 == 0)
        n = n / 2;
      else
        n = 3 * n + 1;
      tempChain++;
    }
    for(int j=0; j<sequence.size(); j++){
      seenNumbers[sequence[j]] = tempChain - j;
    }
    if (longestChain < tempChain) {
      longestChain = tempChain;
      startingNumber = i;
      seenNumbers[startingNumber] = longestChain;
    }
  }
  return 0;
}

/* using recursive takes 10s lol
unordered_map<long long, long long> memo;
long long calculate(long long n) {
  if (n == 1)
    return 1;
  long long next = (n % 2 == 0) ? n / 2 : 3 * n + 1;
  memo[n] = calculate(next) + 1;
  return memo[n];
}

int main() {
  long long longestChain = 0;
  long long startingNumber = 0;
  for (long i = 1000000; i >= 1000000 / 2; i--) {
    long long len = calculate(i);

    if (len > longestChain) {
      longestChain = len;
      startingNumber = i;
    }
  }
  cout << longestChain << endl;
  cout << startingNumber << endl;
  return 0;
}
*/

