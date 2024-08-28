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
    vector<int> nums(n), dp(n,1);
    for(int i=0; i<n; i++) cin>>nums[i];
    int maxi = 1;
    
    vector<int> lis;  
    
    for (int num : nums) {
        // Find the position where num should be placed using binary search
        auto it = lower_bound(lis.begin(), lis.end(), num);
        
        // If the element is greater than all elements in lis, append it to the end
        if (it == lis.end()) {
            lis.push_back(num);
        }
        // Otherwise, replace the existing element with num
        else {
            *it = num;
        }
    }
    
    cout<< lis.size();
    
	return 0;
}