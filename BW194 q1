#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int peak_sum = 0;
        int valley_sum = 0;
        
        // Loop strictly inside boundaries: 0 < i < n - 1
        for (int i = 1; i < n - 1; ++i) {
            // Peak condition
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak_sum += nums[i];
            }
            // Valley condition
            else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                valley_sum += nums[i];
            }
        }
        
        return peak_sum - valley_sum;
    }
};
