#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize input/output operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long x;
    cin >> x;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
