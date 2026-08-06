#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    // Convert the frequency map to a vector of pairs for indexing
    vector<pair<int, int>> elements(counts.begin(), counts.end());
    int d = elements.size();
    long long max_total_damage = 0;

    // Iterate through each unique card type as the majority element
    for (int m = 0; m < d; ++m) {
        int v_m = elements[m].first;
        int C_m = elements[m].second;

        // Try every possible frequency M for this majority element
        for (int M = 1; M <= C_m; ++M) {
            long long current_sum = (long long)M * v_m;
            long long S = 0; // Count of other elements included

            // Greedily take other elements up to the frequency cap M
            for (int i = 0; i < d; ++i) {
                if (i == m) continue;
                int c_i = min(elements[i].second, M);
                S += c_i;
                current_sum += (long long)c_i * elements[i].first;
            }

            // Check the rearrangeability condition: 2 * M <= (M + S) + 2  =>  M <= S + 2
            if (M <= S + 2) {
                max_total_damage = max(max_total_damage, current_sum);
            }
        }
    }

    cout << max_total_damage << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
