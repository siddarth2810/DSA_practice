#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

// Forward declaration
void findTopoSort(int node, vector<int>& vis, stack<int>& st, const unordered_map<int, vector<int>>& adj_mat);

vector<int> topoSort(int N, const unordered_map<int, vector<int>>& adj_mat) {
    stack<int> st;
    vector<int> vis(N, 0);
    
    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            findTopoSort(i, vis, st, adj_mat);
        }
    }
    
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

void findTopoSort(int node, vector<int>& vis, stack<int>& st, const unordered_map<int, vector<int>>& adj_mat) {
    vis[node] = 1;
    
    // Check if the node exists in adj_mat before accessing
    if (adj_mat.find(node) != adj_mat.end()) {
        for (auto it : adj_mat.at(node)) {
            if (!vis[it]) {
                findTopoSort(it, vis, st, adj_mat);
            }
        }
    }
    
    st.push(node);
}

int create_adj_matrix() {
    string line;
    unordered_map<int, vector<int>> adj_matrix;
    int max_vertex = -1;  // Track the highest vertex number
    
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        int u, v;
        char delimiter;
        
        if (ss >> u >> delimiter >> v && delimiter == '|') {
            adj_matrix[u].push_back(v);
            max_vertex = max(max_vertex, max(u, v));
        } else {
            cerr << "Invalid input format: " << line << endl;
            return 1;
        }
    }

    for(auto it: adj_matrix){
        cout << it.first << "->";
        for (auto x: it.second){
            cout << x << " ";
        }
        cout << endl;
    }

    
    // Number of vertices is max_vertex + 1 since vertices are 0-based
    if (max_vertex >= 0) {
        vector<int> result = topoSort(max_vertex + 1, adj_matrix);
        
        // Print the result
        for (int vertex : result) {
           cout << vertex << " ";
        }
        cout << endl;
    }
    
    return 0;
}

int main() {
    return create_adj_matrix();
}

