#include <bits/stdc++.h>
using namespace std;

string multiplyTwo(string n) {
  string res = "";
  int carry = 0;
  int i = n.size() - 1;

  while (i >= 0) {
    int digit = i >= 0 ? n[i--] - '0' : 0;

    int multiple = (digit * 2) + carry;

    carry = multiple / 10;

    res += (multiple % 10) + '0';
  }
  if (carry > 0)
    res += to_string(carry);
  reverse(res.begin(), res.end());

  return res;
}

int main() {
  string n = "32768";

  for (int i = 15; i < 1000; i++) {
    string res = multiplyTwo(n);
    n = res;
  }

  cout << n << endl;

  long long sum = 0;

  for (int i = 0; i < n.size(); i++) {
    sum += n[i] - '0';
  }

  cout << sum << endl;
}

