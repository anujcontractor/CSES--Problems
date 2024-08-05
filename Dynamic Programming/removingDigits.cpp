#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;

vector<int> dp(1e6+1, -1);
int solve(int n){
    if(n <=0 ) return (n == 0 ? 0 : 1e9);
    int temp = n, steps = 1e7;
    
    if(dp[n] != -1) return dp[n];     
    while(temp){
        int digit = temp%10;
        temp /= 10;
        
        if(digit == 0) continue;
        
        int currSteps = solve(n-digit);
        steps = min (1 + currSteps, steps);
    }
    return dp[n] = steps;
}

int32_t main() {
    
    int n;
    cin>>n;
    cout<< solve(n);
    
	return 0;
}