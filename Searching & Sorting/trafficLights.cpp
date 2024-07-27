#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int x, n;
    cin >> x >> n;
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    set<int> lights;
    multiset<int> intervals;

    lights.insert(0);
    lights.insert(x);
    intervals.insert(x);

    for (int i = 0; i < n; ++i) {
        int pos = positions[i];
        auto it = lights.lower_bound(pos);
        int right = *it;
        int left = *prev(it);

        // Remove the old interval length
        intervals.erase(intervals.find(right - left));
        // Insert the new interval lengths
        intervals.insert(pos - left);
        intervals.insert(right - pos);

        // Insert the new traffic light position
        lights.insert(pos);

        // The longest interval is the largest element in the intervals multiset
        cout << *intervals.rbegin() << " ";
    }

    
	return 0;
}