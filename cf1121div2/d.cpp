#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Function to calculate the exact score for a given combination of 1s
ll evaluate(const vector<int>& pos, int n) {
    vector<ll> C(3, 0);
    int current_val = 0;
    int last_idx = 0;
    
    for (int p : pos) {
        int len = p - last_idx;
        C[current_val] += len;
        
        // Even position adds 1, odd position adds 2 (mod 3)
        if (p % 2 == 0) {
            current_val = (current_val + 1) % 3;
        } else {
            current_val = (current_val + 2) % 3;
        }
        last_idx = p;
    }
    C[current_val] += (n + 1 - last_idx);

    ll score = 0;
    for (int i = 0; i < 3; i++) {
        score += C[i] * (C[i] - 1) / 2;
    }
    return score;
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> candidates;
    candidates.push_back({}); // Option with 0 ones (all zeros)
    
    int n3 = n / 3;
    int n2 = n / 2;
    int n4 = n / 4;
    
    // Boundary safe candidate generators
    auto add1 = [&](int x) {
        if (x >= 1 && x <= n) candidates.push_back({x});
    };
    auto add2 = [&](int x, int y) {
        if (x >= 1 && x <= n && y >= 1 && y <= n && x < y) candidates.push_back({x, y});
    };
    auto add3 = [&](int x, int y, int z) {
        if (x >= 1 && x <= n && y >= 1 && y <= n && z >= 1 && z <= n && x < y && y < z) {
            candidates.push_back({x, y, z});
        }
    };
    
    int W = 6; // Window radius around major fractions
    
    // 1-one candidates
    for (int dx = -W; dx <= W; dx++) {
        add1(n3 + dx);
        add1(n2 + dx);
        add1(2 * n3 + dx);
    }
    
    // 2-ones candidates
    for (int dx = -W; dx <= W; dx++) {
        for (int dy = -W; dy <= W; dy++) {
            add2(n3 + dx, 2 * n3 + dy);
            add2(n4 + dx, 3 * n4 + dy);
            add2(n2 + dx, n + dy);
        }
    }
    
    // 3-ones candidates
    for (int dx = -W; dx <= W; dx++) {
        for (int dy = -W; dy <= W; dy++) {
            for (int dz = -W; dz <= W; dz++) {
                add3(n4 + dx, n2 + dy, 3 * n4 + dz);
                add3(n3 + dx, 2 * n3 + dy, n + dz);
                add3(n3 + dx, n2 + dy, 2 * n3 + dz);
            }
        }
    }
    
    ll min_score = 2e18;
    vector<int> best_pos;
    
    // Search the generated pool for the absolute minimum score
    for (auto& cand : candidates) {
        ll s = evaluate(cand, n);
        if (s < min_score) {
            min_score = s;
            best_pos = cand;
        }
    }
    
    // Construct and print the optimal binary string
    string ans(n, '0');
    for (int p : best_pos) {
        ans[p - 1] = '1';
    }
    cout << ans << "\n";
}

int main() {
    // Standard competitive programming I/O optimization
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
