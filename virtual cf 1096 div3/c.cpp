#include <iostream> 
#include <vector> 
using namespace std; 

void solve() { 
    int n; 
    cin >> n; 
    
    // Group categories into separate buckets 
    vector<int> six, two, three, none; 
    for (int i = 0; i < n; ++i) { 
        int val; 
        cin >> val; 
        if (val % 6 == 0) { 
            six.push_back(val); 
        } else if (val % 2 == 0) { 
            two.push_back(val); 
        } else if (val % 3 == 0) { 
            three.push_back(val); 
        } else { 
            none.push_back(val); 
        } 
    } 
    
    // Output groups sequentially to maximize non-divisible blocks
    for (int x : six) cout << x << " "; 
    for (int x : two) cout << x << " "; 
    for (int x : none) cout << x << " "; 
    for (int x : three) cout << x << " "; 
    cout << "\n"; 
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }
    
    return 0;
}
