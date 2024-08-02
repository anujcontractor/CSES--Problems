#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) {cin>>nums[i]; nums[i]+=nums[i-1];}
    
    multiset<int> st;
    for(int i=a; i<=b; i++) st.insert(nums[i]);
    
    int res= *st.rbegin();
    for(int i=1; i+a<=n; i++){
        st.erase(nums[i+a-1]);
        st.insert(nums[min(i+b, n)]);
        res = max(res, *st.rbegin()-nums[i]);
    }
    cout<<res;

	return 0;
}