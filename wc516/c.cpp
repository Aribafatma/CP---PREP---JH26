#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
private:
    // Helper function to get all distinct prime factors of a number
    std::vector<int> getDistinctPrimeFactors(int n) {
        std::vector<int> factors;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            factors.push_back(n);
        }
        return factors;
    }

public:
    int longestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Cache distinct prime factors for unique numbers in nums to avoid recomputation
        std::unordered_map<int, std::vector<int>> factor_cache;
        for (int num : nums) {
            if (factor_cache.find(num) == factor_cache.end()) {
                factor_cache[num] = getDistinctPrimeFactors(num);
            }
        }
        
        std::unordered_map<int, int> prime_counts; // Stores frequency of prime factors in the current window
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // Add prime factors of the current right element to the window
            for (int prime : factor_cache[nums[right]]) {
                prime_counts[prime]++;
            }
            
            // Shrink the window from the left if distinct prime factor count exceeds k
            while (prime_counts.size() > k) {
                for (int prime : factor_cache[nums[left]]) {
                    prime_counts[prime]--;
                    if (prime_counts[prime] == 0) {
                        prime_counts.erase(prime);
                    }
                }
                left++;
            }
            
            // Track the maximum window size achieved
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

// Add this main function to execute and test the code in VS Code
int main() {
    Solution solver;
    
    // Sample inputs from Example 1 in your image
    std::vector<int> nums = {7, 6, 10, 12, 11};
    int k = 3;
    
    int result = solver.longestSubarray(nums, k);
    
    // Should output 3 (corresponding to subarray)
    std::cout << "Longest Subarray Length: " << result << std::endl;
    
    return 0;
}

