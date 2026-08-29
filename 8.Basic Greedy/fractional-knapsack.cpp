#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to store item properties
struct Item {
    double value;
    double weight;
    double ratio;
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long w;
    if (!(cin >> n >> w)) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Sort items by highest efficiency first
    sort(items.begin(), items.end(), compareItems);

    double total_value = 0.0;

    for (int i = 0; i < n; ++i) {
        if (w == 0) break; // Knapsack is full

        if (items[i].weight <= w) {
            // Take the whole item
            w -= items[i].weight;
            total_value += items[i].value;
        } else {
            // Take a fraction of the item to fill the remaining capacity
            total_value += items[i].ratio * w;
            w = 0; // Knapsack is now full
        }
    }

    // Print the result with 9 digits after the decimal point for precision
    cout << fixed << setprecision(9) << total_value << "\n";

    return 0;
}
