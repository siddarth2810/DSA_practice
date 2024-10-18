#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &v, int source, int dest, vector<bool> &vis,
         vector<int> &path) {
  path.push_back(source);
  if (source == dest)

    return true;
  vis[source] = true;

  for (int i = 0; i < v[source].size(); i++) {
    int neighbour = v[source][i];
    if (!vis[neighbour]) {
      if (DFS(v, neighbour, dest, vis, path)) {
        return true;
      }
    }
  }

  path.pop_back(); // backtrack if no path found from this node
  return false;
}

int main() {
  int k = 13;
  vector<vector<int>> adj(k + 1);
  vector<bool> vis(k + 1, false);
  vector<int> path;

  // Read input edges
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int source = 6, dest = 10;
  if (DFS(adj, source, dest, vis, path)) {
    cout << "Path found: ";
    for (int node : path) {
      cout << node << " ";
    }
  } else {
    cout << "No path found";
  }

  return 0;
}

// input
// 12 6
// 8 6
// 6 5
// 1 6
// 8 2
// 7 10
// 1 13
// 1 10
// 5 7
// 1 8
// 11 3
// 3 4
// 3 9
