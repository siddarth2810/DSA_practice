#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> arr) {
    int n = arr.size();
    
    for (int j = 0; j <= n - 2; j++) {
        int minimum = INT_MAX;  
        int count = j; 
        for (int i = j; i < n; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
                count = i;
            }
        }
        int temp = arr[j];
        arr[j] = minimum;
        arr[count] = temp;
    }
    return arr;
}

int main() {
    vector<int> arr = {13, 46, 24, 9, 12};
    vector<int> sortedArr = selectionSort(arr);
    cout << "Sorted Array:" << endl;
    for (auto& it : sortedArr) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
