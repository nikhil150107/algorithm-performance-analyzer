/*
Algorithm Performance Analyzer

This project is a C++ tool designed to compare brute-force and optimized
algorithmic solutions by measuring their actual execution time.

Using the same input, the program runs multiple approaches (e.g., O(n^2)
and O(n)) and reports their runtime, demonstrating the practical impact
of time complexity and algorithm selection.

The objective of this project is to bridge theoretical complexity analysis
with real-world performance measurement.
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

/* --------- BRUTE FORCE MAX SUBARRAY --------- */
int bruteMaxSubarray(vector<int>& a) {
    int n = a.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            ans = max(ans, sum);
        }
    }
    return ans;
}

/* --------- KADANE'S ALGORITHM --------- */
int kadane(vector<int>& a) {
    int curr = a[0], best = a[0];
    for (int i = 1; i < a.size(); i++) {
        curr = max(a[i], curr + a[i]);
        best = max(best, curr);
    }
    return best;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    auto start = high_resolution_clock::now();
    int bruteAns = bruteMaxSubarray(a);
    auto end = high_resolution_clock::now();
    auto bruteTime = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    int kadaneAns = kadane(a);
    end = high_resolution_clock::now();
    auto kadaneTime = duration_cast<milliseconds>(end - start).count();

    cout << "\nRESULTS:\n";
    cout << "Brute Force Answer: " << bruteAns << "\n";
    cout << "Kadane Answer: " << kadaneAns << "\n\n";

    cout << "TIME COMPARISON:\n";
    cout << "Brute Force O(n^2): " << bruteTime << " ms\n";
    cout << "Kadane O(n):        " << kadaneTime << " ms\n";

    return 0;
}
