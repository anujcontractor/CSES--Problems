#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int ans=1;
    sort(v.begin(), v.end());
    
    for(auto i: v){
        if(i == ans) ans++;
        else if(i > ans) break;
    } 
    cout<<ans;

	return 0;
}