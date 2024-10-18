#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // int row = matrix[..][0]
        // int col = matrix[0][..]
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        int col0;

        for (int row = 0; row < row_size; row++)
        {
            for (int col = 0; col < col_size; col++)
            {
                if (matrix[row][col] == 0)
                {

                    // mark the row
                    matrix[row][0] = 0;

                    // mark the col
                    if (col != 0)
                    {
                        matrix[0][col] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }

                } // end of if
            }
        }

        for (int row = 1; row < row_size; row++)
        {
            for (int col = 1; col < col_size; col++)
            {
                if (matrix[row][col] != 0)
                {
                    // check for the fist rows and cols
                    if (matrix[row][0] == 0 || matrix[0][col] == 0)
                    {
                        matrix[row][col] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int row = 0; row < row_size; row++)
            {

                matrix[row][0] = 0;
            }
        }

        if (col0 == 0)
        {

            for (int col = 1; col < col_size; col++)
            {
                matrix[0][col] = 0;
            }
        }

        for (int row = 0; row < row_size; row++)
        {
            for (int col = 0; col < col_size; col++)
            {

                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
};

// reverse an array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7};
    int temp;
    int start = 0;
    int end = (sizeof(arr) / sizeof(arr[0])) - 1;

    while (start <= end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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

// Pascals triangle leetcode
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec;

        for (int row = 0; row < numRows; row++)
        {
            vector<int> newRow(row + 1, 0);
            for (int i : newRow)
                cout << i << " ";
            cout << endl;

            for (int col = 0; col <= row; col++)
            {
                if (row == col || col == 0)
                    newRow[col] = 1;
                else
                    newRow[col] = vec[row - 1][col - 1] + vec[row - 1][col];
            }
            vec.push_back(newRow);
        }

        return vec;
    }
};

//pascal triangle using factorial
class Solution {
public:
    int nCr(int row, int col){
        long long res = 1;
        for(int i=0; i<col; i++){
            res = res * (row - i);
            res = res/(i+1);
        }
        return res;
    }


    vector<vector<int>> generate(int numRows) {
        int matrix[numRows][numRows];
        vector<vector<int>> mat;

        for(int row = 0; row < numRows; row++){
            vector<int> newRow;
            for(int col = 0; col <= row; col++){
               matrix[row][col] = nCr(row, col);
               newRow.push_back(matrix[row][col]);
            }
            mat.push_back(newRow);
    }


    return mat;
    }
};
//pascals traingle optimal
class Solution {
public:
    vector<int> createRow(int row){
        long long res = 1;
        vector<int> newRow;
        newRow.push_back(1);
        for(int col=1; col<row; col++){
            res = res * (row - col);
            res = res/(col);
            newRow.push_back(res);

        }
        return newRow;
    }


    vector<vector<int>> generate(int numRows) {
        int matrix[numRows][numRows];
        vector<vector<int>> mat;
        int res =1;

        for(int row = 1; row <= numRows; row++){
            mat.push_back(createRow(row));
    }


    return mat;
    }
};

