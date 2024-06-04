//leetcode 136
//XOR of zero and any number is the number itself
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int j =0;
        for(int i: nums){
             j = j^i;
        }

        return j;
     
    }
};
