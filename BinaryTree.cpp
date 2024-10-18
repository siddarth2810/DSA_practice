//construct binary tree using the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    n = 10;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> tree(n + 1, -1);

    for (int i = 0; i < n; i++) {
        int parent = (i - 1) / 2;
        if (parent >= 0) {
            if (i == 2 * parent + 1) {
                tree[parent] = v[i];
            } else {
                tree[parent] = v[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << tree[i] << " ";
    }
    return 0;
}
