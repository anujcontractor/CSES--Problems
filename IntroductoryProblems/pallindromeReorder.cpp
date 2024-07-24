#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    
    vector<int> frq(26,0);
    for(char c: s) frq[c-'A']++;
    int odd = -1;
    for(int i=0; i<26; i++){
        if(frq[i]%2 == 1){
            if(odd != -1) {cout<<"NO SOLUTION"; return 0;}
            else odd = i;
        }
    }
    
    for(int i=0; i<26; i++){
        for(int j=0; j<frq[i]/2; j++) cout<<(char)(i+'A');
    }
    if(odd != -1) cout<<(char)(odd+'A');
    for(int i=25; i>=0; i--){
        for(int j=0; j<frq[i]/2; j++) cout<<(char)(i+'A');
    }

	return 0;
}