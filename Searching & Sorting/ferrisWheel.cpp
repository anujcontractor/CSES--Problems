#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,m;
    cin>>n>>m;
    vector<int> child(n);
    for(int i=0; i<n; i++) cin>>child[i];
    sort(child.begin(), child.end());
    int res=0;
    int l=0, h=n-1;
    while(l<=h){
        if(child[l] + child[h] <= m){
            res++;
            l++;
            h--;
        }
        else{
            res++;
            h--;
        }
    }
    cout<<res;
    
	return 0;
}