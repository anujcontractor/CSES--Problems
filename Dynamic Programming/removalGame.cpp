#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;


int32_t main() {
    
    // int n;
    // cin>>n;
    // vector<int> nums(n);
    // for(int i=0; i<n; i++) cin>>nums[i];
    
    // int playerA=0, playerB=0;
    // int i=0, j=nums.size()-1;
    // bool flag = true;
    // while(i<j){
    //     if(flag){
    //         playerA += max(nums[i], nums[j]);
    //         if(nums[i] > nums[j]) i++;
    //         else j--;
    //         flag = false;
    //     }
    //     else{
    //         playerB += max(nums[i], nums[j]);
    //         if(nums[i] > nums[j]) i++;
    //         else j--;
    //         flag = true;
    //     }
    // }
    // cout<<playerA<<endl;
    
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    for (int length = 1; length <= n; length++) {
        for (int i = 0; i + length - 1 < n; i++) {
            int j = i + length - 1;
            if (i == j) {
                dp[i][j] = nums[i];
            } else {
                dp[i][j] = max(nums[i] + (prefix_sum[j + 1] - prefix_sum[i + 1]) - dp[i + 1][j],
                               nums[j] + (prefix_sum[j] - prefix_sum[i]) - dp[i][j - 1]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
    
	return 0;
}