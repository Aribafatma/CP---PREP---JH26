#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int T0 = 0, T1 = 0;
    for (char c : s) {
        if (c == '0') T0++;
        else T1++;
    }

    // Quick impossibility check based on the deletion condition
    if (abs(T0 - T1) > 2) {
        cout << -1 << "\n";
        return;
    }

    // dp[start_bit][end_bit] stores the maximum length of an alternating subsequence
    vector<vector<int>> dp(2, vector<int>(2, -INF));

    for (char ch : s) {
        int c = ch - '0';
        // Extend existing alternating subsequences
        for (int start = 0; start < 2; ++start) {
            if (dp[start][1 - c] != -INF) {
                dp[start][c] = max(dp[start][c], dp[start][1 - c] + 1);
            }
        }
        // A new subsequence can also start at the current character
        dp[c][c] = max(dp[c][c], 1);
    }

    int max_kept_len = -1;

    // Check all 4 possible boundary combinations of alternating subsequences
    for (int start = 0; start < 2; ++start) {
        for (int end = 0; end < 2; ++end) {
            if (dp[start][end] == -INF) continue;

            // Calculate K0 - K1 (kept 0s minus kept 1s) based on start and end bits
            int K0_minus_K1 = 0;
            if (start == end) {
                K0_minus_K1 = (start == 0) ? 1 : -1;
            }

            // Verify if the remaining deleted characters can alternate perfectly
            if (abs((T0 - T1) - K0_minus_K1) <= 1) {
                max_kept_len = max(max_kept_len, dp[start][end]);
            }
        }
    }

    if (max_kept_len == -1) {
        cout << -1 << "\n";
    } else {
        cout << n - max_kept_len << "\n";
    }
}

int main() {
    // Optimize standard I/O streams for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
