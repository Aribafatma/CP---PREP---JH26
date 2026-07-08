#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of first array
        int arr1[1005];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        int m;
        cin >> m; // Size of second array
        int arr2[1005];
        bool visited[1005] = {false}; // Track which elements of arr2 are already matched
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        // Compare each element of arr1 with elements of arr2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If elements match and this arr2 element hasn't been used yet
                if (arr1[i] == arr2[j] && !visited[j]) {
                    cout << arr1[i] << " ";
                    visited[j] = true; // Mark as used so it isn't matched again
                    break;             // Move to the next element in arr1
                }
            }
        }
        cout << endl; // New line after each test case
    }

    return 0;
}
