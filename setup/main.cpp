#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int> arr, int element) {
  int high = arr.size() - 1;
  int low = 0;

  while (low < high) {
    int mid = (low + high) / 2;
    if (arr[mid] < element) {
      low = mid + 1;
      continue;
    }
    if (arr[mid] > element) {
      high = mid;
      continue;
    }
    cout << mid << endl;
    cout << arr[mid] << endl;
    return true;
  }

  return false;
}

int main() {
  vector<int> arr = {1, 3, 5, 6, 8, 11};
  bool ok = bs(arr, 1);
  if (ok)
    cout << "le goo";
  else
    cout << "lol";
  return 0;
}
