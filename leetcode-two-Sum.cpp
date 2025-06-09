#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &v, int target) {
  map<int, int> num;

  for (int i = 0; i < v.size(); i++) {
    int comp = target - v[i];

    if (num.find(comp) != num.end()) {
      return {num[comp], i};
    }

    num[v[i]] = i;
  }
  return {};
}

int main() {
  vector<int> v = {5, 1, 2, 3, 4, 6, 7, 8, 9, 10};
  int target = 9;
  vector<int> x = twoSum(v, target);

  for (auto it : x) {
    cout << it << " "; 
  }
  cout << endl;

  return 0;
}

