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


