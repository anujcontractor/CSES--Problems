#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    sort(nums.begin(), nums.end());
    
    int median = nums[n/2];
    int res=0;
    for(int i=0; i<n; i++){
        res += abs(median-nums[i]);
    }
    cout<<res;
    
	return 0;
}