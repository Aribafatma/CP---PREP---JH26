#include <iostream>
#include <vector>
#include <algorithm>

// Custom GCD function that works on all older C++ versions
int get_gcd(int a, int b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

class Solution {
public:
    int maxValidSplits(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;

        // Precompute prefix and suffix GCDs
        std::vector<int> pref(n), suff(n);
        
        pref[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = get_gcd(pref[i - 1], nums[i]);
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = get_gcd(suff[i + 1], nums[i]);
        }

        int max_score = 0;

        // Try removing each element at index j
        for (int j = 0; j < n; ++j) {
            int left_gcd = (j > 0) ? pref[j - 1] : 0;
            int right_gcd = (j < n - 1) ? suff[j + 1] : 0;
            int total_gcd = get_gcd(left_gcd, right_gcd);

            int current_left_gcd = 0;
            int current_score = 0;

            // Count valid split points
            for (int i = 0; i < n - 1; ++i) {
                if (i == j) continue; 

                current_left_gcd = get_gcd(current_left_gcd, nums[i]);
                
                if (current_left_gcd == total_gcd) {
                    current_score++;
                }
            }
            max_score = std::max(max_score, current_score);
        }

        return max_score;
    }
};

// Main function to run local test case
int main() {
    Solution solver;
    
    // Example 1 from the image
    std::vector<int> nums = {10, 30, 15, 10};
    
    int result = solver.maxValidSplits(nums);
    std::cout << "Maximum score: " << result << std::endl;
    
    return 0;
}
