// Approach 1: Observation
// every second onw cell is growing from middle outward till next right cell, in all 4 direction
class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; i++) {
            ans += (i-1)*4;
        }
        return ans;
    }
};