#include <iostream>
#include <vector>

using namespace std;

void solve_brute_force() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long good_subarrays = 0;

    // Check all subarrays of odd length
    for (int l = 0; l < n; l++) {
        long long current_alt_sum = 0;
        for (int r = l; r < n; r++) {
            // Alternate signs inside the subarray
            if ((r - l) % 2 == 0) {
                current_alt_sum += a[r];
                // If length is odd and alternating sum > 0, it's a good subarray
                if (current_alt_sum > 0) {
                    good_subarrays++;
                }
            } else {
                current_alt_sum -= a[r];
            }
        }
    }
    cout << good_subarrays << "\n";
}

// Added the missing main function to handle compilation and test cases
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        solve_brute_force();
    }
    return 0;
}
