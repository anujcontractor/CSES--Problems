#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Customer {
    int arrival, departure, index;
};

bool compareCustomers(const Customer &a, const Customer &b) {
    if (a.arrival != b.arrival) return a.arrival < b.arrival;
    return a.departure < b.departure;
}

int main() {
    int n;
    cin >> n;
    vector<Customer> customers(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }

    sort(customers.begin(), customers.end(), compareCustomers);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> roomAssignments(n);
    int roomCount = 0;

    for (const auto &customer : customers) {
        if (!pq.empty() && pq.top().first < customer.arrival) {
            roomAssignments[customer.index] = pq.top().second;
            pq.pop();
        } else {
            roomAssignments[customer.index] = ++roomCount;
        }
        pq.push({customer.departure, roomAssignments[customer.index]});
    }

    cout << roomCount << endl;
    for (int i = 0; i < n; ++i) {
        cout << roomAssignments[i] << " ";
    }
    cout << endl;

    return 0;
}
