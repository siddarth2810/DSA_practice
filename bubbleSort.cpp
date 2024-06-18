#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> arr){
    int j =0;
    int size = arr.size();
    int temp;
    while(j<=size-2){
        for(int i=j+1; i<=arr.size()-1; i++){
            if(arr[j] > arr[i]){
             temp = arr[j];
             arr[j] = arr[i];
             arr[i] = temp;
            }
        }
        j++;
    }
    return arr;
}

int main() {
    vector<int> arr = {13, 46, 24, 9, 12,99,5,4,7};
    vector<int> sortedArray = bubbleSort(arr);
    for(auto& it: sortedArray){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
