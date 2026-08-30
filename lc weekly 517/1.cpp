#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countSpecialIntegers(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Step 1: Compress contiguous duplicates
        std::vector<int> compressed;
        compressed.push_back(nums[0]);
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                compressed.push_back(nums[i]);
            }
        }
        
        // Step 2: Count frequencies of each number in the compressed array
        std::unordered_map<int, int> counts;
        for (int num : compressed) {
            counts[num]++;
        }
        
        // Step 3: Count how many numbers appear exactly once
        int specialCount = 0;
        for (const auto& pair : counts) {
            if (pair.second == 1) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};

// --- ADD THIS MAIN FUNCTION TO FIX YOUR ERROR ---
int main() {
    Solution solver;
    
    // Example 1 Test Case
    std::vector<int> test1 = {1, 2, 2, 1};
    std::cout << "Example 1 Output: " << solver.countSpecialIntegers(test1) << " (Expected: 1)\n";
    
    return 0;
}
