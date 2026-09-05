#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // 1. Read the productivity array 'a' first
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 2. Read the post positions 'b' second
    vector<int> posts(m);
    for (int i = 0; i < m; i++) {
        cin >> posts[i];
    }
    
    // Sort the post positions to divide the array into sequential segments
    sort(posts.begin(), posts.end());

    long long total = 0;
    long long sum = 0;
    int p_idx = 0; // Tracks which post checkpoint we are looking for next

    // 3. Process the segments
    for (int i = 0; i < n; i++) {
        sum += a[i];

        // Check if the current 1-based position (i + 1) hits a post boundary
        if (p_idx < m && (i + 1) == posts[p_idx]) {
            total += abs(sum); // Maximize by taking the absolute positive sum
            sum = 0;           // Reset for the next segment
            p_idx++;           // Move to the next post
        }
    }

    // Add the remaining elements after the last post (cannot be flipped)
    total += sum;

    cout << total << "\n";
}

int main() {
    // Fast I/O to prevent Time Limit Exceeded
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
