#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


int32_t main() {
    
    int n;
    cin >> n;
    
    int S = n * (n + 1) / 2;
    
    // If S is odd, it's impossible to divide the set into two equal subsets
    if (S % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int target = S / 2;
    
    // DP array to store the number of ways to get each sum
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // There is one way to achieve a sum of 0 (by choosing no elements)
    
    // Fill the DP table
    for (int num = 1; num <= n; num++) {
        for (int sum = target; sum >= num; sum--) {
            dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
        }
    }
    
    // Since each valid partition is counted twice, divide the result by 2
    cout << (dp[target] * 500000004LL) % MOD << endl; // Modular division by 2 using 500000004
    
    return 0;
    
    
	return 0;
}