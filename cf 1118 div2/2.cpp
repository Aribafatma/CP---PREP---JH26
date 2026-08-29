#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> freq(m + 2, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        freq[a]++;
    }
    
    // Compute suffix sums for O(1) queries of elements >= x
    std::vector<int> suff(m + 2, 0);
    for (int i = m; i >= 1; --i) {
        suff[i] = suff[i + 1] + freq[i];
    }
    
    int max_carrots = 0;
    
    // Case 1: Target length matches the cut length x
    for (int x = 1; x <= m; ++x) {
        int current = suff[x];
        if (2 * x <= m) {
            current += freq[2 * x];
        }
        max_carrots = std::max(max_carrots, current);
    }
    
    // Case 2: Target length L != x. We pair the most frequent elements.
    // Gather all lengths with their frequencies
    std::vector<std::pair<int, int>> candidates;
    for (int i = 1; i <= m; ++i) {
        if (freq[i] > 0) {
            candidates.push_back({freq[i], i});
        }
    }
    
    // Sort by frequency descending
    std::sort(candidates.rbegin(), candidates.rend());
    
    // Take up to the top 4 highest frequencies to check distinct pairs
    int limit = std::min(4, (int)candidates.size());
    for (int i = 0; i < limit; ++i) {
        for (int j = i + 1; j < limit; ++j) {
            int len1 = candidates[i].second;
            int len2 = candidates[j].second;
            
            // Ensure one is not exactly twice the other (handled by Case 1)
            if (std::max(len1, len2) != 2 * std::min(len1, len2)) {
                max_carrots = std::max(max_carrots, candidates[i].first + candidates[j].first);
            }
        }
    }
    
    std::cout << max_carrots << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
