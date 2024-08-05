#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;

vector<vector<int>> dp(501, vector<int> (501, 1e6));
int solve(int a, int b){
    if(a > b) swap(a, b);
    if(dp[a][b] != 1e6) return dp[a][b];
    if(a == b) return dp[a][b] = 0;
    if(a == 1 || b == 1) return dp[a][b] = (a == 1 ? b-1 : a-1);
    for(int i = 1; i < a; i++)
        dp[a][b] = min(dp[a][b], solve(i, b) + solve(a-i, b) + 1);
    for(int i = 1; i < b; i++)
        dp[a][b] = min(dp[a][b], solve(a, i) + solve(a, b-i) + 1);
    return dp[a][b];
}
int32_t main() {
	// Your code goes here;
    int a, b;
    cin>>a>>b;
    cout<<solve(a,b);

	return 0;
}