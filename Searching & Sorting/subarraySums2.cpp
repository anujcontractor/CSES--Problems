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
    map<int,int> frq;
    frq[0] = 1;
    int prefix=0, res=0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        prefix += nums[i];
        res += frq[prefix-x];
        frq[prefix]++;
    }
    cout<<res;
    
	return 0;
}