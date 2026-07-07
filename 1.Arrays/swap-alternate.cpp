#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases
    
    while (t > 0) {
        int n;
        cin >> n; // Read the size of the array
        
        int a[100005]; // Standard array to hold elements
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read array elements
        }
        
        // Loop through the array, skipping by 2 every time
        for (int i = 0; i < n - 1; i = i + 2) {
            // Swap the current element with the next element
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
        
        // Print the final swapped array
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl; // Move to the next line for the next testcase
        
        t--; // Move to the next test case
    }
    
    return 0;
}
