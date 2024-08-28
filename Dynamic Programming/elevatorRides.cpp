#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int solve(int i, int w, vector<int> &weights, int curr){
    if(curr> w || i >= weights.size()) return 0;

    int take = 0;
    if(curr + weights[i] < w){
        take = 1 + solve(i+1, w, weights, curr+weights[i]);
    }
    int notTake = solve(i+1, w, weights, curr);
}

int32_t main(){

    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
      cin >> weights[i];
    }

  return 0;
}