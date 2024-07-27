#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    vector<int> res(n);
    for(int i=0; i<n; i++) cin>>res[i];
    int cnt=0;
    for(int i=1; i<n; i++){
        if(res[i] < res[i-1]){
            while(res[i] < res[i-1]) {res[i]+=1; cnt++;}
        }
    }
    
    cout<<cnt;

	return 0;
}