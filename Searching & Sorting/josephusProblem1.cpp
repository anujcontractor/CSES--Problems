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
    deque<int> children;
    for (int i = 1; i <= n; ++i) children.push_back(i);

    while (!children.empty()) {
        children.push_back(children.front());
        children.pop_front(); // Skip one child
        cout<<children.front()<<" ";
        children.pop_front(); // Remove the next child
    }


    
	return 0;
}