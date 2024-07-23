#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin>>n;
    vector<long long> res;
    res.push_back(n);
    while(n != 1){
        if(n%2 == 0) n = n/2;
        else n = n*3 + 1;
        res.push_back(n);
    }
    for(auto i: res) cout<<i<<" ";

	return 0;
}