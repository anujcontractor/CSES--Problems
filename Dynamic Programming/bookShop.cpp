#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int i, vector<int>& price, vector<int>& pages, int x, vector<vector<int>>& dp){
    if(x <= 0 || i >= price.size()) return 0;
    
    if(dp[i][x] != -1) return dp[i][x];
    
    int notTake = solve(i+1,price,pages,x,dp);
    int take = 0;
    if(price[i] <= x) take = pages[i] + solve(i+1,price,pages,x-price[i],dp);
    
    return dp[i][x] = max(notTake, take);
}

int32_t main() {
	// Your code goes here;
    int n,x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i=0; i<n; i++) cin>>price[i];
    for(int i=0; i<n; i++) cin>>pages[i];
    
    // vector<vector<int>> dp(n+1, vector<int> (x+1,-1));
    // cout<<solve(0, price, pages, x, dp);
    
    vector<int> dp(x + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    
    cout << dp[x];

	return 0;
}