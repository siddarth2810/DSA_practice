#include <bits/stdc++.h>
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

int main (){
    int n1, n2;
    int total_dist = 0;
    int similarity_score = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap1;
    priority_queue<int, vector<int>, greater<int>> minHeap2;
    unordered_map<int, int> freq_l2;
    for(int i=0; i<1000; i++){
        cin >> n1 >> n2;
        minHeap1.push(n1);
        minHeap2.push(n2);

        freq_l2[n2]++;
    }

    while(!minHeap1.empty() && !minHeap2.empty()){
        int s1 = minHeap1.top();
        int s2 = minHeap2.top();
        minHeap1.pop();
        minHeap2.pop();
        total_dist += abs(s1 - s2);
    }
    return total_dist;
    //part 2 same as below
}

/* bruteforce
int main(){
    int n1,n2;
    vector<int> l1;
    vector<int> l2;
    for(int i=0; i<1000; i++){
        cin >> n1;
        cin >> n2;
        l1.push_back(n1);
        l2.push_back(n2);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    int sum = 0;
    int final_sum = 0;
    for(int i=0; i<l1.size(); i++){
        l1[i] > l2[i] ? sum = l1[i] - l2[i] : sum = l2[i] - l1[i]; 
        final_sum += sum;
    }
    cout << final_sum;
// Part 2
    map<int, pair<int, int>> freq;
    for(int num: l1){
        freq[num].first++;
    }
    for(int num: l2){
        freq[num].second++;
    }
    int final_similarity = 0;
    for(const auto& [num, counts]: freq){
        int similarity_score = num*counts.first;
        similarity_score *= counts.second;
        final_similarity += similarity_score;
    }
    cout << final_similarity;
    return 0;
}
*/

