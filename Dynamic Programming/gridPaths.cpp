#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;

int solve(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& dp){
    if(i >= grid.size() || j >= grid[0].size() || i<0 || j<0 || grid[i][j] == '*') return 0;
    if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int down = solve(i+1,j,grid,dp)%MOD;
    int right = solve(i,j+1,grid,dp)%MOD;
    
    return dp[i][j] = (down+right)%MOD;
}


int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    vector<vector<int>> dp(n, vector<int> (n,-1));
    vector<vector<char>> grid(n, vector<char> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    
    cout<< solve(0,0,grid,dp);

	return 0;
}