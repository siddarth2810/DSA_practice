#include<bits/stdc++.h>
using namespace std;
void swap(int l, int r,vector<int>& nums ){
	int temp;
	temp = nums[l];
	nums[l] = nums[r];
	nums[r] = temp;
}

void reverse(int l, int r,vector<int>& nums ){
	if (l >=r ) return;
	swap(l, r, nums);
	reverse(l+1, r-1, nums);
}

void reverse_with_single_pointer(int i, vector<int> &nums){
	int n = nums.size();
	if (i >= n/2) return;
	swap(i, n-i-1, nums);
	reverse_with_single_pointer(i+1, nums);
}

int main () {
	vector<int> nums = {1,2,3,4,5,7,6};
	//reverse_with_single_pointer(0, nums);
	//reverse(0,nums.size()-1, nums);
	for(auto it: nums){
	cout << it << " ";
	}
	cout << endl;
	return 0;
}

