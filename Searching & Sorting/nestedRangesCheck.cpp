#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Range {
    int start, end, index;
    bool contains_other = false;
    bool contained_by_other = false;
};

bool compare(const Range &a, const Range &b) {
    if (a.start != b.start) return a.start < b.start;
    return a.end > b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Range> ranges(n);

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), compare);

    int max_end = -1;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].end <= max_end) {
            ranges[i].contained_by_other = true;
        }
        max_end = max(max_end, ranges[i].end);
    }

    int min_end = 1e9 + 1;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].end >= min_end) {
            ranges[i].contains_other = true;
        }
        min_end = min(min_end, ranges[i].end);
    }

    vector<int> contains_other(n), contained_by_other(n);
    for (int i = 0; i < n; ++i) {
        contains_other[ranges[i].index] = ranges[i].contains_other;
        contained_by_other[ranges[i].index] = ranges[i].contained_by_other;
    }

    for (int i = 0; i < n; ++i) {
        cout << contains_other[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << contained_by_other[i] << " ";
    }
    cout << endl;

    return 0;
}
