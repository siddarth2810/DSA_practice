#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool peek(vector<int> &flowerbed, int n, int &currPos) {
    if (currPos + 1 < flowerbed.size() && flowerbed[currPos + 1] == 0) {
      currPos++;
      return true;
    }
    return false;
  }
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int i = 0;
    while (i < flowerbed.size() && flowerbed[i] != 1) {
        if (peek(flowerbed, 1, i)) {
          n--;
        }
        i++;
    }
    if (n == 0) {
      return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  cout << s.canPlaceFlowers(flowerbed, 1);
  return 0;
}
