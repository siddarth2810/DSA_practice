class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MIN;
        int sum = 0;
        for (int a = 0; a < n; a++) {
                sum = max(nums[a], sum + nums[a]);
                best = max(best,sum);
        }
        return best;
    }
};
