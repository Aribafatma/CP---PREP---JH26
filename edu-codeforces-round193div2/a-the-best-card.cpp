#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 200005;
vector<bool> is_prime(MAX_VAL, true);

// Precompute primes using the Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_VAL; i += p)
                is_prime[i] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    // Check if the largest card (n + 1) is a prime number
    if (is_prime[n + 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
