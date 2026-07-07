#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases
    
    while (t > 0) {
        int n;
        cin >> n; // Read the size of the array
        
        int unique_num = 0; // Stores the final unique element
        
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num; // Read each number one by one
            
            unique_num = unique_num ^ num; // XOR operation
        }
        
        cout << unique_num << endl; // Print the unique number
        
        t--; // Move to next test case
    }
    
    return 0;
}
