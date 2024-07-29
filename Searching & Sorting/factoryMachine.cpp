#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>& machine, int mid, int t){
    int sum = 0;
    for(int i=0; i<machine.size(); i++){
        int temp = mid/machine[i];
        sum += temp;
        if(sum >= t) return true;
    }
    return false;
}
int32_t main() {
	// Your code goes here;
    int n,t;
    cin>>n>>t;
    vector<int> machine(n);
    for(int i=0; i<n; i++) cin>>machine[i];
    sort(machine.begin(), machine.end());
    
    int low = machine[0];
    int high = 1ll * machine[n-1] * t;
    int res = high;
    
    while(low <= high){
        int mid = (low+high) >> 1;
        // cout<<mid<<" ";
        if(check(machine, mid, t)){
            res = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<res;
    

	return 0;
}