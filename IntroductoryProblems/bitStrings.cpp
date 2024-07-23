#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9+7;

int32_t poweR(int n, int exp){
    if(exp == 0) return 1;
    
    int temp = poweR(n,exp/2);
    int res = (temp%MOD)*(temp%MOD)%MOD;
    
    if(exp%2 == 1) res = (res*n)%MOD;
    
    return res;    
}
int32_t main() {
    int n;
    cin>>n;
    cout<< poweR(2,n);

	return 0;
}