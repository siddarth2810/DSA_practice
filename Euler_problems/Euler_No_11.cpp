#include <bits/stdc++.h>
using namespace std;

int main() {
  string line, inp;
  vector<vector<int>> grid;

  while (getline(cin, line)) {
    vector<int> row;
    // stringstream splits it by spaces
    stringstream ss(line);
    int num;

    while (ss >> num) {
      row.push_back(num);
    }
    grid.push_back(row);
  }

  int colSize = 20;
  int rowSize = 20;

  long greatestProduct = 0;
  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      // Right
      if (j + 3 < colSize) {
        long product = 1;
        for (int k = 0; k < 4; k++)
          product *= grid[i][j + k];
        greatestProduct = max(greatestProduct, product);
      }

      // Down
      if (i + 3 < rowSize) {
        long product = 1;
        for (int k = 0; k < 4; k++)
          product *= grid[i + k][j];
        greatestProduct = max(greatestProduct, product);
      }

      // Diagonal Down-Right
      if (i + 3 < rowSize && j + 3 < colSize) {
        long product = 1;
        for (int k = 0; k < 4; k++)
          product *= grid[i + k][j + k];
        greatestProduct = max(greatestProduct, product);
      }

      // Diagonal Down-Left
      if (i + 3 < rowSize && j - 3 >= 0) {
        long product = 1;
        for (int k = 0; k < 4; k++)
          product *= grid[i + k][j - k];
        greatestProduct = max(greatestProduct, product);
      }
    }
  }

  cout << greatestProduct << endl;
  return 0;
}

