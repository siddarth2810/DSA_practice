#binary_search_non_recursive
class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) high = mid -1;
            else if (target > nums[mid]) low = mid +1; 
        }
        return -1;
    }
};
//optimzed_way_of_writing_injertion_element
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        int mid; 
        while(low<=high){
            mid = (high + low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid -1;
            }
            else {
                    low = mid + 1;  
            }
          
        }
        return ans;
    }
};
//my way of of the above code
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low<=high){

            mid = (low+high)/2;
            if (target > nums[high] ) return high+1;
            else if (target < nums[low]) return low;
 
            else if(nums[mid] == target) return mid;
            else if(target < nums[mid]) {
                high = mid -1;
                if(target > nums[mid-1]) return mid;
            }
            else if (target > nums[mid]){
             low = mid +1; 
                if(target < nums[mid + 1]) return mid+1; 
            }
          
        }
        return -1;
    }
};
