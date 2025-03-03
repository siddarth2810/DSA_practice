#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;

  // array
  int arr[n];
  for (int i = 0; i < n; i += 1) {
    arr[i] = i;
  }

  // init hash
  int hash[13] = {0};
  for (int i = 0; i < n; i += 1) {
    hash[arr[i]] += 1;
  }

  // initialize the number of inupts

  int q;
  cout << "the number of inputs";
  cin >> q;

  while (q--) {
    int number;
    cin >> number;

    cout << hash[number] << endl;
  }
}
