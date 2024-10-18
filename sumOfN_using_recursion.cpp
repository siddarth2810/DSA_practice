#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sumOfN_param(int sum, int n) {
    if (n == 0) {
      cout << sum << endl;
      return;
    }
    cout << "sum +n " << sum + n << " at n value " << n << endl;
    sumOfN_param(sum + n, n - 1);
  }

  int sumOfN_func(int n) {
    if (n == 0) {
      return 0;
    }
    return n + sumOfN_func(n - 1);
  }
};

int main() {
  Solution s;
  // s.sumOfN_param(0,3);
  //int result = s.sumOfN_func(3);
  //cout << result << endl;
  return 0;
}

