#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

long long pow10(int x){
    long long res = 1;
    for(int i = 0; i < x; i++) res *= 10;
    return res;
}

int solve(long long N){
    if(N < 9) return (int) N+1;

    int len = 1;
    while(9 * pow10(len-1) * len < N){
        N -= 9 * pow10(len-1) * len;
        len++;
    }

    string S = to_string(pow10(len-1) + N/len);
    return (int) (S[N%len] - '0');
}

int32_t main(){

  int t;
  cin>>t;
  while(t--){
    int k;
    cin>>k;
    cout<<solve(k-1)<<endl;
  }

  return 0;
}