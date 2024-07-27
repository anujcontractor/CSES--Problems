#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void solve(int depth, int from, int to){
    if(depth == 1){
        cout<<from<<" "<<to<<endl;
        return;
    }
    int other = 6 - from - to;
    solve(depth-1, from, other);
    cout<<from<<" "<<to<<endl;
    solve(depth-1, other, to);
}
int main() {
    int n;
    cin>>n;
    cout<<(1<<n) -1<<endl;
    solve(n,1,3);

	return 0;
}