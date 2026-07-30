#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to check if a maximum page limit 'max_pages' is feasible for K students
bool isValid(const vector<long long>& A, int K, long long max_pages) {
    int students = 1;
    long long current_pages = 0;
    
    for (long long pages : A) {
        if (current_pages + pages > max_pages) {
            // Assign to the next student
            students++;
            current_pages = pages;
            if (students > K) {
                return false;
            }
        } else {
            current_pages += pages;
        }
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    if (!(cin >> N >> K)) return 0;
    
    vector<long long> A(N);
    long long max_book = 0;
    long long total_pages = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        max_book = max(max_book, A[i]);
        total_pages += A[i];
    }
    
    // Edge case: If there are more students than books, allocation is impossible
    if (K > N) {
        cout << -1 << "\n";
        return 0;
    }
    
    // Binary Search range
    long long low = max_book;
    long long high = total_pages;
    long long ans = -1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (isValid(A, K, mid)) {
            ans = mid;         // 'mid' is feasible, try to look for a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;     // 'mid' is too small, increase allowed pages
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
