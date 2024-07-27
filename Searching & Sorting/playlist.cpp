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
    int ans=1;
    int i=0, j=0;
    set<int> st;
    while(j<n){
        if(st.find(nums[j]) == st.end()){
            st.insert(nums[j]);
            ans = max(ans, (int)st.size());
            j++;
        }
        else{
            // while(i<=j) 
            st.erase(nums[i++]);
            // j++;
            // i++;
        }
    }
    cout<<ans;
	return 0;
}