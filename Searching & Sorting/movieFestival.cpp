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
    vector<pair<int,int>> movie(n);
    // for(int i=0; i<n; i++){
    //     int a,b;
    //     cin>>a>>b;
    //     movie.push_back({a,1});
    //     movie.push_back({b,-1});
    // }
    // sort(movie.begin(), movie.end(), [](pair<int,int> a, pair<int,int> b){
    //     return a.first == b.first ? a.second < b.second : a.first < b.first;
    // });
    
    // int curr=0, res = 0;
    // for(int i=0; i<movie.size(); i++){
    //     curr += movie[i].second;
    //     res = max(res,curr);
    // }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movie[i] = {b, a}; 
    }
    sort(movie.begin(), movie.end());

    int res = 0, last_end_time = 0;
    for (int i = 0; i < n; i++) {
        if (movie[i].second >= last_end_time) {
            res++;
            last_end_time = movie[i].first;
        }
    }
    
    cout<<res;
    
	return 0;
}