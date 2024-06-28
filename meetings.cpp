#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
            int hash[10] = {0};

            for(int i=0; i<meetings.size(); i++){

                for(int j=0; j<2; j++){

                 
                    hash[meetings[i][j]] += meetings[i][j];

                }
            }


            for(int i=0; i<12; i++){
               cout << hash[i]<< endl;
            }

            return 0;
};
};

int main(){
    Solution s;
    vector<vector<int>> meetings = {{1, 3}, {2, 4}, {3, 5}, {4, 6}};
    int days = 10;
    cout << s.countDays(days, meetings);
    return 0;
}
