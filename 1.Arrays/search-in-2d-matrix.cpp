#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    if (!(cin >> n >> m >> x)) return 0;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            if (val == x) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
