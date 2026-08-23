#include <iostream>
#include <string>
#include <bitset>

class Solution {
public:
    bool isAsciiPalindromic(std::string s) {
        std::string binary_str = "";
        
        // Step 1: Convert each character to its 8-bit binary representation
        for (char c : s) {
            binary_str += std::bitset<8>(c).to_string();
        }
        
        // Step 2: Check if the full binary string is a palindrome
        int left = 0;
        int right = binary_str.length() - 1;
        
        while (left < right) {
            if (binary_str[left] != binary_str[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};

// Add this main function to run it in VS Code
int main() {
    Solution solver;
    
    // Test Case 1 (From the example: "ff")
    std::string test1 = "ff";
    if (solver.isAsciiPalindromic(test1)) {
        std::cout << "Test 1 passed! \"" << test1 << "\" is ASCII Palindromic.\n";
    } else {
        std::cout << "Test 1 failed!\n";
    }

    // Test Case 2
    std::string test2 = "abc";
    if (!solver.isAsciiPalindromic(test2)) {
        std::cout << "Test 2 passed! \"" << test2 << "\" is NOT ASCII Palindromic.\n";
    } else {
        std::cout << "Test 2 failed!\n";
    }

    return 0;
}
