#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    vector<pair<int,int>> customer;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        customer.push_back({a,1});
        customer.push_back({b,-1});
    }
    sort(customer.begin(), customer.end(), [](pair<int,int> a, pair<int,int> b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    
    int curr=0, res = 0;
    for(int i=0; i<customer.size(); i++){
        curr += customer[i].second;
        res = max(res,curr);
    }
    
    cout<<res;
    
	return 0;
}