class Solution {
public:
    unordered_map<int,int> dp;
    int dpf(int i, int n) {
        if(i > n) return 0;
        if(i == n) return 1;
        if(dp.count(i) != 0) return dp[i];
        int ans = dpf(i+1,n) + dpf(i+2,n);
        return dp[i] = ans;
    }
    int climbStairs(int n) {
        return dpf(0,n);
    }
};