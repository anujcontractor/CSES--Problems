#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

class Task{
public:
  int duration;
  int deadline;
};

int32_t main() {
	// Your code goes here;
    int n;
    cin>>n;
    vector<Task> t(n);
    for(int i=0; i<n; i++) cin>>t[i].duration >>t[i].deadline;
    // int maxD=0;
    // for(auto i: t) maxD += i.duration;
    // vector<int> durations(maxD+1);
    sort(t.begin(), t.end(),[](Task a, Task b){
        return a.duration == b.duration ? a.deadline < b.deadline : a.duration < b.duration;
    });
    
    int res = 0, last=0;
    for(int i=0; i<n; i++){
        last += t[i].duration;
        res += t[i].deadline - last;
    }
    cout<<res;

	return 0;
}