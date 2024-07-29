#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod (int num, int n){
    return (num%n + n)%n;
}
int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    vector<int> nums(n);
    int prefix=0, res=0;
    map<int,int> frq;
    frq[0] = 1;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        prefix = mod(prefix+nums[i], n);
        res += frq[prefix];
        frq[prefix]++;
    }
    cout<<res;
    
	return 0;
}