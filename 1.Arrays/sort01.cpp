#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t; // 1. Fix: Read the number of test cases first
    
    while (t--) {
        int n;
        cin >> n; // 2. Fix: Read 'n' BEFORE creating the array
        
        int a[n];
        int c0 = 0, c1 = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // 3. Fix: You must read the array elements from input
            
            if (a[i] == 0) {
                c0++;
            } else { 
                c1++;
            }
        }
        
        // 4. Fix: Added spaces (" ") between numbers as required by the problem
        // print all zeros
        for (int i = 1; i <= c0; i++) {
            cout << "0 ";
        }
        // print all ones
        for (int i = 1; i <= c1; i++) {
            cout << "1 ";
        }
        
        cout << "\n"; // 5. Fix: Move to a new line for the next testcase
    }
    
    return 0;
}
