#include <bits/stdc++.h>
using namespace std;

int main() {
  string line, inp;
  while (getline(cin, line)) {
    inp += line;
  }
  long final = 0;

  for (int i = 0; i <= inp.size() - 13; i++) {
    long product = 1;
    for (int j = i; j < i + 13; j++) {
      // skip over 0s
      if (inp[j] == '0') {
        product = 0;
        break;
      }
      product *= (inp[j] - '0');
    }
    final = max(final, product);
  }
  cout << "final is: " << final << endl;
  return 0;
}

