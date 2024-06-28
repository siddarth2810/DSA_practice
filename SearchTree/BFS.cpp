#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &v, int source, int dest, vector<bool> &vis, vector<int> &path) {
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        path.push_back(node);

        if (node == dest) {
            return true;
        }

        for (int i = 0; i < v[node].size(); i++) {
            if (!vis[v[node][i]]) {
                q.push(v[node][i]);
                vis[v[node][i]] = true;
            }
        }
    }

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

    int source = 6, dest = 13;
    if (BFS(adj, source, dest, vis, path)) {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    } else {
        cout << "Path does not exist between " << source << " and " << dest << endl;
    }

    return 0;
}


// input
//12 6
//8 6
//6 5
//1 6
//8 2
//7 10
//1 13
//1 10
//5 7
//1 8
//11 3
//3 4
//3 9


