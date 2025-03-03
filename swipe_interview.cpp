#include<bits/stdc++.h>
using namespace std;

int  main () {
    //[8,9,10,0,5,0]
    vector<int> arr = {8,0,9,10,0,5,8};
    int n = arr.size();
    vector<int> dist(n,n); 

    int last_zero = -1;
    for(int i=0; i<n; i++){
        if (arr[i] == 0 ){
            last_zero = i;
            dist[i] = 0;
        }else if (last_zero != -1){
            dist[i] = i - last_zero;
        }
    }
    
    last_zero = -1;
    for(int i=arr.size()-1; i>=0 ; i--){
        if (arr[i] == 0){
            last_zero = i;
            dist[i] = 0;
        } else if (last_zero != -1){
            dist[i] = min(dist[i], last_zero - i);
        }
    }

    for(auto it: dist){
        cout << it << " "; 
    }

}
