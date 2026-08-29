#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    int m;
    cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    // Sort both greed factors and cookie sizes
    sort(g.begin(), g.end());
    sort(c.begin(), c.end());

    int child_ptr = 0;
    int cookie_ptr = 0;

    // Use two pointers to match cookies to children
    while (child_ptr < n && cookie_ptr < m) {
        if (c[cookie_ptr] >= g[child_ptr]) {
            // This cookie satisfies the current child
            child_ptr++;
        }
        // Move to the next cookie regardless of whether it was used or too small
        cookie_ptr++;
    }

    // The index of child_ptr represents the total number of content children
    cout << child_ptr << "\n";

    return 0;
}
