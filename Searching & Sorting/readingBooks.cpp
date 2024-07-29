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
    vector<int> time(n);
    int sum=0;
    for(int i=0; i<n; i++) {cin>>time[i]; sum+=time[i];}
    int maxi = *max_element(time.begin(), time.end());
    cout<<max(2*maxi,sum);
	return 0;
}