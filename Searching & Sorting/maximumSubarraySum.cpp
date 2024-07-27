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
    
    int curr=0, res=INT_MIN;
    for(int i=0; i<n; i++){
        if(curr < 0) curr=0;
        curr += nums[i];
        
        res = max(curr,res);
    }
    cout<<res;
    
	return 0;
}