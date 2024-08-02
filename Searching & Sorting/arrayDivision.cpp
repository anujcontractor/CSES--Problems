#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, int k, vector<int> &nums){
    int x=1, sum=0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(sum > mid){x++; sum=nums[i];}
    }
    return x <= k;
}

int32_t main() {
	// Your code goes here;
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    int low = *max_element(nums.begin(), nums.end());
    int high = 1e18;
    
    while(low <= high){
        int mid = (low+high)/2;
        if(check(mid,k,nums)) high = mid-1;
        else low = mid+1;
    }  
    cout<<low;  
    

    
    
	return 0;
}