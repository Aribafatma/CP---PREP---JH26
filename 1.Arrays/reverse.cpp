#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the array
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the array elements
    }
    
    // Reverse the array in-place using two pointers
    int left = 0;
    int right = n - 1;
    while (left < right) {
        swap(a[left], a[right]); // Swap elements
        left++;
        right--;
    }
    
    // Print the reversed array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
