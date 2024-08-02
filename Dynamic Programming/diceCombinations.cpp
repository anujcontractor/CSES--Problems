#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9+7;
vector<int> dp;
int countWays(int n) {
    if (n == 0) return 1;  
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n];  

    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways = (ways + countWays(n - i)) % MOD;  
    }

    return dp[n] = ways;  
}

int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    dp.resize(1e6+1,-1);
    cout<<countWays(n);

	return 0;
}