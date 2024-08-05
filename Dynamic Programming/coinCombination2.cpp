#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

// vector<vector<int>> dp(101, vector<int> (1e6+1, -1));
// int solve(int i, vector<int> &nums, int x){
//     if(i >= nums.size() || x < 0) return 0;
//     if(i == nums.size()-1) return (x % nums[i] == 0);
    
//     if(dp[i][x] != -1) return dp[i][x];
    
//     int notPick = solve(i+1, nums, x);
//     int pick = 0;
//     if(nums[i] <= x) pick = solve(i,nums,x-nums[i]);
    
//     // return (pick+notPick) % MOD;
//     return dp[i][x] = (pick+notPick) % MOD;
// }

int32_t main() {
    
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    // cout<< solve(0,nums,x);
    
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        // Update the dp array from back to front.
        for (int j = nums[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - nums[i]]) % MOD;
        }
    }
    
    cout << dp[x] << endl;
    
	return 0;
}