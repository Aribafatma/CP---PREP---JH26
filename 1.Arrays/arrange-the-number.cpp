#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases
    
    while (t--) {
        int n;
        cin >> n; // Read n
        
        // Step 1: Print all odd numbers from 1 to n
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        
        // Step 2: Find the largest even number <= n
        int start_even = (n % 2 == 0) ? n : n - 1;
        
        // Step 3: Print all even numbers from start_even down to 2
        for (int i = start_even; i >= 2; i -= 2) {
            cout << i << " ";
        }
        
        cout << "\n"; // Move to the next line for the next testcase
    }
    
    return 0;
}
