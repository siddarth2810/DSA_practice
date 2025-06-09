#include <bits/stdc++.h>
using namespace std;

/*triangle[i + 1][j] (the number directly below it), or*/
/*triangle[i + 1][j + 1] (the number to the bottom-right)*/
long maxAdjSum(vector<vector<int>> tri, int row, int col) {
	if (row == tri.size() -1 ) 
		return tri[row][col]; 
	long left = maxAdjSum(tri, row+1, col);
	long right = maxAdjSum(tri, row+1, col+1);

	return tri[row][col] + max(left, right);
}

int main() {
  string line, inp;

  vector<vector<int>> triangle;
  while (getline(cin, line)) {
    vector<int> row;
    stringstream ss(line);
    int num;
    while (ss >> num) {
      row.push_back(num);
    }
    triangle.push_back(row);
  }

  long lol = maxAdjSum(triangle, 0, 0);
  cout << lol << endl;

  return 0;
}

