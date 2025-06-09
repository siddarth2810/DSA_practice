#include <bits/stdc++.h>
using namespace std;

// long long cant be used coz 50 digit is out of its capacity

string addString(string a, string b) {
  string res = "";
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;

  while (i >= 0 || carry || j >= 0) {
    int digitA = i >= 0 ? a[i--] - '0' : 0;
    int digitB = j >= 0 ? b[j--] - '0' : 0;

    int sum = digitA + digitB + carry;

    carry = sum / 10;

    //% gives last digit
    res += (sum % 10) + '0';
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  string line, sum = "0";
  long long number;

  while (getline(cin, line)) {
    sum = addString(sum, line);
  }
  cout << sum.substr(0, 10) << endl;

  return 0;
}
