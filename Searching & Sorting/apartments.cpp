#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// Your code goes here;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicant(n), app(m);
    for(int i=0; i<n; i++) cin>>applicant[i];
    for(int i=0; i<m; i++) cin>>app[i];
    sort(applicant.begin(), applicant.end());
    sort(app.begin(), app.end());

    int res = 0;
    int i = 0, j = 0;

    while(i < n && j < m) {
        if(abs(applicant[i] - app[j]) <= k) {
            res++;
            i++;
            j++;
        }else if(applicant[i] < app[j]) i++;
        else j++;
    }

    cout<<res;
	return 0;
}