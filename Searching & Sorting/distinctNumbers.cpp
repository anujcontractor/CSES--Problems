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
    set<int> st;
    while(n--){
        int temp;
        cin>>temp;
        st.insert(temp);
    }
    cout<<st.size();
	return 0;
}