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
    int sum=0, res=0, l=0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        sum += nums[i];
        while(sum > x) sum -= nums[l++];
        if(sum == x) res++;
    }
    cout<<res;

	return 0;
}