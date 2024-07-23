#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a<=2*b && b<=2*a && (a+b)%3 == 0) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }

	return 0;
}