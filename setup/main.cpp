#include<bits/stdc++.h>
using namespace std;
// get all subsequences of array

void subsequences(int idx, vector<int> &nums, vector<int> arr){
	int n = arr.size();
	if(idx >= n){
		for(auto it: nums){
			cout << it << " ";
		}
		cout << endl;
		return;
	}
	nums.push_back(arr[idx]);
	subsequences(idx+1, nums, arr);
	nums.pop_back();
	subsequences(idx+1, nums, arr);
}

int main () {
	vector<int> arr = {2,3,6}; 
	vector<int> nums = {};
	subsequences(0,nums, arr);
	return 0;
}
