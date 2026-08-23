#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
        std::vector<std::vector<int>> result;
        
        // Sort the array to find gaps in increasing order
        std::sort(nums.begin(), nums.end());
        
        // Use long long to safely avoid any integer overflow during addition/subtraction
        long long current = lower;
        
        for (int num : nums) {
            // Skip numbers outside or below our current target range
            if (num < current) {
                continue;
            }
            // Stop if we exceed the upper bound
            if (num > upper) {
                break;
            }
            
            // If there's a gap between current expected and the actual number
            if (num > current) {
                result.push_back({(int)current, num - 1});
            }
            
            // Move current past the found number
            current = (long long)num + 1;
        }
        
        // Catch any remaining missing range at the end
        if (current <= upper) {
            result.push_back({(int)current, upper});
        }
        
        return result;
    }
};

// Add this main function to execute and test the code in VS Code
int main() {
    Solution solver;
    
    // Sample inputs from Example 1
    std::vector<int> nums = {3, 9, 7};
    int lower = 1;
    int upper = 12;
    
    std::vector<std::vector<int>> missing_ranges = solver.findMissingRanges(nums, lower, upper);
    
    // Print the results out to the console
    std::cout << "Missing Ranges:\n[";
    for (size_t i = 0; i < missing_ranges.size(); ++i) {
        std::cout << "[" << missing_ranges[i][0] << "," << missing_ranges[i][1] << "]";
        if (i < missing_ranges.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]\n";
    
    return 0;
}
