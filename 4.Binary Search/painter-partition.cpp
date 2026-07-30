#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to check if a maximum time of 'max_time' is feasible with 'k' painters
bool isValid(const vector<long long>& a, int k, long long max_time) {
    int painters = 1;
    long long current_time = 0;
    
    for (long long board : a) {
        if (current_time + board > max_time) {
            // Allocate to a new painter
            painters++;
            current_time = board;
            if (painters > k) {
                return false;
            }
        } else {
            current_time += board;
        }
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<long long> a(n);
    long long max_board = 0;
    long long total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_board = max(max_board, a[i]);
        total_sum += a[i];
    }
    
    // Binary Search range
    long long low = max_board;
    long long high = total_sum;
    long long ans = high;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (isValid(a, k, mid)) {
            ans = mid;        // 'mid' is feasible, try to look for a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;    // 'mid' is too small, increase the allowed time
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
