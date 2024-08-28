#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;


struct Project {
    int start, end, reward;
};

int findLastNonConflicting(const vector<Project>& projects, int currentIndex) {
    int low = 0, high = currentIndex - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (projects[mid].end < projects[currentIndex].start) {
            if (projects[mid + 1].end < projects[currentIndex].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int32_t main() {
    int n;
    cin >> n;

    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        return a.end < b.end;
    });

    vector<long long> dp(n, 0);

    dp[0] = projects[0].reward;

    for (int i = 1; i < n; ++i) {
        // Case 1: We don't take the current project, so dp[i] = dp[i-1]
        dp[i] = dp[i - 1];

        // Case 2: We take the current project
        int last = findLastNonConflicting(projects, i);
        long long includeReward = projects[i].reward;
        if (last != -1) {
            includeReward += dp[last];
        }

        // Take the maximum of the two cases
        dp[i] = max(dp[i], includeReward);
    }

    cout << dp[n - 1] << endl;

    return 0;
}