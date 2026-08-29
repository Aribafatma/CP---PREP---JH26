#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, limit;
    if (!(cin >> n >> limit)) return 0;

    vector<int> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
    }

    // Sort weights in ascending order
    sort(people.begin(), people.end());

    int left = 0;
    int right = n - 1;
    int boats = 0;

    // Use two pointers to pair people up greedily
    while (left <= right) {
        // If the lightest and heaviest can share a boat
        if (people[left] + people[right] <= limit) {
            left++; // Move to the next lightest person
        }
        // The heaviest person always takes a boat (either alone or paired)
        right--;
        boats++;
    }

    cout << boats << "\n";

    return 0;
}
