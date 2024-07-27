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
    vector<int> res;
    res.push_back(nums[0]);
    for(int i=1; i<n; i++){
        auto it = upper_bound(res.begin(), res.end(), nums[i]);
        if(it != res.end()){
            *it = nums[i];
        }
        else res.push_back(nums[i]);
    }
    
    cout<<res.size();
	return 0;
}