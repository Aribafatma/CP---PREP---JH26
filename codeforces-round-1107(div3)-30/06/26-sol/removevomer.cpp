#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count the number of contiguous blocks of identical characters
    int blocks = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            blocks++;
        }
    }
    
    // If there are exactly 2 blocks, it reduces to "01" or "10" (length 2)
    if (blocks == 2) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
