#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<long long> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the numbers so that x <= y <= z
    sort(arr.begin(), arr.end());
    
    long long x = arr[0];
    long long y = arr[1];
    long long z = arr[2];
    
    // The minimum range is either the initial range (z - x) 
    // or the median (y) obtained after replacing z with x + y.
    long long ans = min(z - x, y);
    
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
