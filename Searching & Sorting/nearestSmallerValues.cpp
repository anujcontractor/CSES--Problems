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
    vector<int> nums(n), pos(n);
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        
        while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
        
        if(s.empty()) pos[i] = 0; // No smaller previous element
        else pos[i] = s.top() + 1; // Adjust to 1-based index
        
        s.push(i);
        cout << pos[i] << " ";
    }
    

	return 0;
}