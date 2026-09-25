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
        int val;
        cin >> val;
        counts[val]++;
    }

    vector<int> result;
    
    // Process round by round
    while (!counts.empty()) {
        vector<int> current_round;
        
        for (auto it = counts.begin(); it != counts.end(); ) {
            current_round.push_back(it->first);
            it->second--;
            
            // Remove from the map if all copies of this element are used
            if (it->second == 0) {
                it = counts.erase(it);
            } else {
                ++it;
            }
        }
        
        // Sort elements in descending order to maximize the tie-breaking rule
        sort(current_round.rbegin(), current_round.rend());
        
        for (int val : current_round) {
            result.push_back(val);
        }
    }

    // Output the optimal rearranged array
    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
