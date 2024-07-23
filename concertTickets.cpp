#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // int t,c;
    // cin>>t>>c;
    // vector<int> tickets(t);
    // for(int i=0; i<t; i++) cin>>tickets[i];
    // for(int i=0; i<c; i++) cin>> cutomer[i];
    // vector<int> res(c,-1);
    
    // sort(tickets.begin(), tickets.end());
    // for(int i=0; i<c; i++){
    //     int l=0, h=t-1;
    //     while(l <= h){
    //         int mid = (l + h) << 1;
    //         if(tickets[mid] <= cutomer[i]){
    //             int temp1=mid;
    //             while(temp1 < t && tickets[temp1] <= cutomer[i]) temp1++;
    //             res[i] = tickets[temp1];
    //             tickets[temp1] = -1;
    //         }
    //         else h = mid-1;
    //     }
    // }
    
    // for(auto i : res) cout<<i<<endl;
    
    int t, c;
    cin >> t >> c;

    multiset<int> tickets;
    vector<int> customer(c);

    for (int i = 0; i < t; i++) {
        int ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (int i = 0; i < c; i++) {
        cin >> customer[i];
    }

    vector<int> res(c, -1);

    for (int i = 0; i < c; i++) {
        auto it = tickets.upper_bound(customer[i]);
        if (it != tickets.begin()) {
            --it;
            res[i] = *it;
            tickets.erase(it);
        }
    }

    for (auto i : res) {
        cout << i << endl;
    }


	return 0;
}