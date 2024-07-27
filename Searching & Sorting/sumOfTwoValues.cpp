#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    map<int,int> mp;
    
    for(int i=0; i<n; i++){
        if(mp.find(x-nums[i]) != mp.end()){
            cout<<mp[x-nums[i]]+1<<" "<<i+1;
            return 0;
        }
        mp[nums[i]] = i;
    }
    cout<<"IMPOSSIBLE";
	return 0;
}