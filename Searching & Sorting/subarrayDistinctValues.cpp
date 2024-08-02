#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    
    unordered_map<int, int> freq;
    int res = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        freq[nums[i]]++;
        
        while (freq.size() > k) {
            freq[nums[j]]--;
            if (freq[nums[j]] == 0) freq.erase(nums[j]);
            j++;
        }
        
        res += i - j + 1;
    }
    
    cout<<res;
    
    
	return 0;
}