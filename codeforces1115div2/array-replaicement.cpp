#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> evens, odds;
    vector<int> is_odd(n - 1);

    // 1. Calculate adjacent differences and group them by parity
    for (int i = 0; i < n - 1; ++i) {
        long long diff = a[i + 1] - a[i];
        if (abs(diff) % 2 != 0) {
            odds.push_back(diff);
            is_odd[i] = 1;
        } else {
            evens.push_back(diff);
            is_odd[i] = 0;
        }
    }

    // 2. Sort both groups to make the final values as small as possible
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    // 3. Reconstruct the array directly from sorted differences
    int e_ptr = 0, o_ptr = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long current_diff = (is_odd[i] ? odds[o_ptr++] : evens[e_ptr++]);
        a[i + 1] = a[i] + current_diff;
    }

    // 4. Output the result
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
