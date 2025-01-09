// Approach 1: memoization
class Solution {
public:
    unordered_map<int,int> dp;
    int numSquares(int n) {
        if(n==0) return 0;
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
        int ans = 1e9;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans,1 + numSquares(n-i*i));
        }
        return dp[n] = ans;
    }
};