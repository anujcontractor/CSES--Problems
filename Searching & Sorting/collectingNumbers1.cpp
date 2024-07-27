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
    vector<int> nums(n), pos(n+1);
    for(int i=0; i<n; i++) {cin>>nums[i]; pos[nums[i]]=i;}
    
    int ans=1;
    for(int i=2; i<=n; i++){
        if(pos[i] < pos[i-1]) ans++;
    }
    cout<<ans;
	return 0;
}