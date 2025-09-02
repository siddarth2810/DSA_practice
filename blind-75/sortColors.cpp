class Solution {
public:
    //bubble sort
    void sortColors(vector<int>& nums) {
        for (int j = 0; j < nums.size(); j++) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                    int temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
            }
        }
    }
};
