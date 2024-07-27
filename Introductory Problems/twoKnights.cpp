#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int32_t main() {
    int N;
    cin >> N;
    for (int k = 1; k <= N; k++) {
        // Total ways to place two knights on k x k board
        ll totalWays = (ll)k * k * (k * k - 1) / 2;
        
        // Ways in which two knights attack each other
        ll attackWays = 4 * (k - 1) * (k - 2);
        
        // Valid non-attacking ways
        ll validWays = totalWays - attackWays;
        
        cout << validWays << endl;
    }
    return 0;
}