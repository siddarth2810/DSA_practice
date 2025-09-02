#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  vector<int> mpp(128, 0);
  int counter = t.size();
  int begin = 0;
  int end = 0;
  int d = INT_MAX;
  int head = 0;

  for (auto it : t) {
    mpp[it]++;
  }

  while (end < s.size()) {
    char c = s[end++];
    if (--mpp[c] >= 0) {
      counter--;
    }

    while (counter == 0) {
      if (d > end - begin) {
        d = end - begin;
        head = begin;
      }

      char temp = s[begin++];
      if (++mpp[temp] > 0)
        counter++;
    }
  }
    cout << s.substr(head, d);
  return d;
}

