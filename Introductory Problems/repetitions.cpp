#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin>>s;
    
    int curr=1, maxi=1;
    for(int i=1; i<s.length(); i++){
        if(s[i] == s[i-1]) curr++;
        else curr=1;
        maxi = max(maxi, curr);
    }
    
    cout<<maxi;

	return 0;
}