#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    while(n>0){ n/= 5; ans+= n;}
    cout<<ans;

	return 0;
}