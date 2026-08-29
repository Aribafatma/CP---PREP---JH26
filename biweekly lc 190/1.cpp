#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int minBishopMoves(std::vector<int>& source, std::vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        
        // Case 1: Already at the target
        if (sr == tr && sc == tc) {
            return 0;
        }
        
        // Case 2: Different square colors (unreachable)
        if ((sr + sc) % 2 != (tr + tc) % 2) {
            return -1;
        }
        
        // Case 3: On the same diagonal (1 move)
        if (std::abs(sr - tr) == std::abs(sc - tc)) {
            return 1;
        }
        
        // Case 4: Same color but different diagonals (2 moves)
        return 2;
    }
};

// The missing entry point that fixes your terminal error:
int main() {
    Solution solver;
    
    // Test Case Example from the problem description
    std::vector<int> source = {8, 1};
    std::vector<int> target = {1, 8};
    
    int result = solver.minBishopMoves(source, target);
    
    std::cout << "Minimum Moves: " << result << std::endl;
    
    return 0;
}
