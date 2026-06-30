#include <iostream>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    
    if (x % y == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
