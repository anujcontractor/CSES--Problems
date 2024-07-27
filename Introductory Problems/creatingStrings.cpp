#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    string original = s; 
    vector<string> res;
    res.push_back(s); 
    while (next_permutation(s.begin(), s.end())) {
        res.push_back(s);
        if (s == original) {
            break; 
        }
    }
    cout<<res.size()<<endl;
    sort(res.begin(), res.end());
    for(string s: res) cout<<s<<endl;


	return 0;
}