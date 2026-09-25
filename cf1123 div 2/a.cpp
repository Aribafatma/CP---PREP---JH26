#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    int total_coins = 0;
    
    // Check symmetric pairs from both ends towards the center
    for (int i = 0; i < n / 2; ++i) {
        int j = n - 1 - i;
        if (s[i] != s[j]) {
            if (s[i] == c || s[j] == c) {
                total_coins += 1;
            } else {
                total_coins += 2;
            }
        }
    }

    cout << total_coins << "\n";
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
