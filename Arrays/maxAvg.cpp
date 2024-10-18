#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
      // sliding window
      int left = 0, right = 0;
      double average = 0;
      double maxAverage = INT_MIN;
      while (right < nums.size()) {
          average += nums[right];
          if (right - left + 1 == k) {
              maxAverage = max(maxAverage, average / k);
              average -= nums[left];
              left++;
          }
          right++;
      }
      return maxAverage;
  }
};
int main() {
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << s.findMaxAverage(nums, k) << endl;
    return 0;
}

