#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    
    vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;  

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        cout << (dp[amount] == INT_MAX ? -1 : dp[amount]) << endl;
    

	return 0;
}