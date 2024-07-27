#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,q;
    cin>>n>>q;
    vector<int> nums(n), pos(n+1);
    for(int i=0; i<n; i++) {cin>>nums[i]; pos[nums[i]]=i;}
    
    int ans=1;
    for(int i=2; i<=n; i++) if(pos[i] < pos[i-1]) ans++;
    
    while(q--){
        int a,b;
        cin>>a>>b;
        a--; b--;
        int n1 = nums[a], n2 = nums[b];
        int ans2 = 0;
        
        if(n1-1 >= 1){
            if(pos[n1] < pos[n1-1]) ans2++;
        }
        if(n1+1 <= n){
            if(pos[n1+1] < pos[n1]) ans2++;
        }
        if(n2-1 >= 1 && n2-1 != n1){
            if(pos[n2] < pos[n2-1]) ans2++;
        }
        if(n2+1 <= n && n2+1 != n1){
            if(pos[n2+1] < pos[n2]) ans2++;
        }
        ans -= ans2;
        // cout<<"ans2: "<<ans2<<endl;
        
        swap(nums[a], nums[b]);
        swap(pos[nums[a]], pos[nums[b]]);
        int ans3=0;
        
        if(n1-1 >= 1){
            if(pos[n1] < pos[n1-1]) ans3++;
        }
        if(n1+1 <= n){
            if(pos[n1+1] < pos[n1]) ans3++;
        }
        if(n2-1 >= 1 && n2-1 != n1){
            if(pos[n2] < pos[n2-1]) ans3++;
        }
        if(n2+1 <= n && n2+1 != n1){
            if(pos[n2+1] < pos[n2]) ans3++;
        }
        ans += ans3;
        cout<<ans<<endl;
    }
	return 0;
}