#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int index, int currentSum, int totalSum, 
     vector<int>& weight, int& minDiff) {
    if (index == weight.size()) {
        int otherSum = totalSum - currentSum;
        int diff = abs(currentSum - otherSum);
        minDiff = min(minDiff, diff);
        return;
    }
    
    solve(index + 1, currentSum + weight[index], totalSum, weight, minDiff);
    solve(index + 1, currentSum, totalSum, weight, minDiff);
}

int32_t main() {
    int n;
    cin>>n;
    vector<int> weight(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        totalSum += weight[i];
    }
    
    int minDiff = INT_MAX;
    solve(0, 0, totalSum, weight, minDiff);
    
    cout << minDiff << endl;
	return 0;
}