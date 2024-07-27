#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,m;
    cin>>n>>m;
    vector<int> customer(m);
    multiset<int> tickets;
    for(int i=0; i<n; i++) {
        int ticket;
        cin>>ticket;
        tickets.insert(ticket);
    }
    for(int i=0; i<m; i++) cin>> customer[i];
    
    vector<int> res(m,-1);
    for(int i=0; i<m; i++){
        auto it = tickets.upper_bound(customer[i]);
        if(it != tickets.begin()){
            --it;
            res[i] = *it;
            tickets.erase(it);
        }
    }
    for(auto i: res) cout<<i<<endl;
    
	return 0;
}