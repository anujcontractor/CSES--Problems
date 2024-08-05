#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9+7;

set<int> ans;
void solve(int i, vector<int>& nums, int& sum){
    if(i >= nums.size()){
        ans.insert(sum);
        return;
    }
    
    sum += nums[i];
    solve(i+1, nums, sum);
    sum -= nums[i];
    solve(i+1, nums, sum);
    
}
int32_t main() {

    // int n;
    // cin>>n;
    // vector<int> nums(n);
    // for(int i=0; i<n; i++) cin>>nums[i];
    // int sum = 0;
    // solve(0ll,nums,sum);
    // ans.erase(0);
    // cout<<ans.size()<<endl;
    // for(auto i: ans) cout<<i<<" ";

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    
    set<int> possible_sums;
    possible_sums.insert(0); 
    
    for (int i = 0; i < n; i++) {
        vector<int> current_sums(possible_sums.begin(), possible_sums.end());
        for (int sum : current_sums) {
            possible_sums.insert(sum + coins[i]);
        }
    }
    
    possible_sums.erase(0); 
    
    cout << possible_sums.size() << endl;
    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    
	return 0;
}