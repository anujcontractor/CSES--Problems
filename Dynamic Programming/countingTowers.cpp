#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;


vector<int> ans(1e6+1);
int32_t main() {
	// Your code goes here;
    int t;
    cin>>t;
        int prev0 = 1, prev1 = 1; 
        for (int i = 1; i <= 1e6; i++) {
            int new0 = (2LL * prev0 + prev1) % MOD;
            int new1 = (4LL * prev1 + prev0) % MOD;
            ans[i] = (prev0 + prev1) % MOD;
            prev0 = new0;
            prev1 = new1;
        }
    while(t--){
        int n;
        cin>>n;
        cout<< ans[n] << endl;
    }
    

	return 0;
}