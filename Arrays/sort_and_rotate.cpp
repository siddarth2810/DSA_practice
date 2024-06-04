// sorted and rotated array check

class Solution
{
public:
    void Reverse(vector<int> &arr, int start, int end)
    {
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    bool check(vector<int> &nums)
    {

        int n = nums.size();
        int d = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                d = i;
                break;
            }
        }

        Reverse(nums, 0, d - 1);
        Reverse(nums, d, n - 1);
        Reverse(nums, 0, n - 1);

        vector<int> sorted;
        for (int i = 1; i <= n; i++)
        {
            sorted.push_back(i);
        }

        if (is_sorted(nums.begin(), nums.end()))
            return true;

        // check if the rotated array when rotated back is equal to the sorted array
        if (nums == sorted)
            return true;
        else
            return false;
    }
};


