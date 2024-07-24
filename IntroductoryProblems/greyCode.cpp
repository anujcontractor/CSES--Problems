#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> generateGrayCode(int n) {
    // Initialize the result with the base cases for n=0 and n=1
    vector<string> result;
    result.push_back("0");
    result.push_back("1");

    // Loop to build the sequence for lengths from 2 to n
    for (int i = 2; i <= n; i++) {
        int currentSize = result.size();

        // Append reverse of the current result
        for (int j = currentSize - 1; j >= 0; j--) {
            result.push_back(result[j]);
        }

        // Add '0' to the first half
        for (int j = 0; j < currentSize; j++) {
            result[j] = "0" + result[j];
        }

        // Add '1' to the second half
        for (int j = currentSize; j < result.size(); j++) {
            result[j] = "1" + result[j];
        }
    }

    return result;
}

int main() {
	int n;
    cin>>n;
    vector<string> grayCode = generateGrayCode(n);

    for (const string& code : grayCode) cout << code << endl;

	return 0;
}