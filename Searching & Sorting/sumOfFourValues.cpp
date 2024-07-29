#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,x;
    cin>>n>>x;
    // vector<int> nums(n);
    // unordered_map<int,int> mp;
    // for(int i=0; i<n; i++) {cin>>nums[i]; mp[nums[i]]=i;}
    
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         int sum = nums[i] + nums[j];
    //         if(mp.find(x-sum) != mp.end() && (i!=mp[x-sum] && j!=mp[x-sum])){
    //             cout<<i+1<<" "<<j+1<<" "<<mp[x-sum]+1;
    //             return 0;
    //         }
    //     }
    // }
    vector<pair<int,int>> nums(n);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        nums[i] = {temp, i+1};
    }
    sort(nums.begin(), nums.end());
    
    for(int m=0; m<n-2; m++){    
        for(int i=m+1; i<n-1; i++){
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i].first + nums[j].first + nums[k].first + nums[m].first;
                if (sum == x) {
                    cout << nums[j].second << " " << nums[k].second << " " << nums[i].second <<" "<<nums[m].second;
                    return 0;
                } else if (sum < x) j++;
                else k--;
            }
        }
    }
    
    cout<<"IMPOSSIBLE";
    
	return 0;
}