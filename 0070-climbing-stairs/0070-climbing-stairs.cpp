class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = dp[i+1] + dp[i+2];
        int dpi1 = 1, dpi2 = 1, dpi = 2;
        for(int i = n-2; i >= 0; i--) {
            // cout<<i<<":"<<dpi1<<dpi2<<endl;
            dpi = dpi1 + dpi2;
            dpi2 = dpi1;
            dpi1 = dpi;
        }
        return dpi1;
    }
};