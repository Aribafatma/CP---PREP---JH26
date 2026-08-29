#include <iostream>
#include <vector>

// Manual GCD function that works on any C++ standard version
long long get_gcd(long long a, long long b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Calculates GCD without requiring C++17
    long long ans = get_gcd(a[0], a[n - 1]);
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
