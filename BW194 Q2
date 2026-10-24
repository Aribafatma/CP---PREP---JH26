#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total_subarrays = 0;
        long long current_length = 0;
        
        for (int num : nums) {
            // Check if the current element satisfies the loose bounds
            if (num >= minK && num <= maxK) {
                current_length++;
                total_subarrays += current_length;
            } else {
                // Reset the length when an out-of-bound element is encountered
                current_length = 0;
            }
        }
        
        return total_subarrays;
    }
};
