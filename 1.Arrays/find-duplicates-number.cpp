#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        int n;
        cin >> n; // Read size of the array

        int arr[1001];
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Read array elements
        }

        // Look for the duplicate by comparing every pair
        int duplicate = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    duplicate = arr[i];
                    break;
                }
            }
            if (duplicate != -1) break;
        }

        cout << duplicate << endl;
    }

    return 0;
}
