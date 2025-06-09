#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, long long> cache;

long long countRoutes(int row, int col) {
  if (row == 0 || col == 0)
    return 1;
  pair<int, int> key = {row, col};

  if (cache.count(key)) {
    return cache[key];
  }
  cache[key] = countRoutes(row - 1, col) + countRoutes(row, col - 1);
  return cache[key];
}

int main() {
  /*
   00 01 02
   10 11 12
   20 21 22
   * */

  // recuursive approach
  //  long long route = countRoutes(20, 20);

  // iterative dp approach
  int N = 2;
  vector<vector<long long>> matrix(N + 1, vector<long long>(N + 1));

  for (long long i = 0; i <= N; i++) {
    matrix[i][0] = 1;
  }
  for (long long j = 0; j <= N; j++) {
    matrix[0][j] = 1;
  }

  for (long long i = 1; i <= N; i++) {
    for (long long j = 1; j <= N; j++) {
      matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
    }
  }

  for (long long i = 0; i <= N; i++) {
    for (long long j = 0; j <= N; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

