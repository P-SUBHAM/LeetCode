// Approach 1: DP memoization
class Solution {
public:
    map<pair<int,int>,int> dp;
    int uniquePaths(int m, int n) {
        if(dp.find({m,n})!=dp.end()) return dp[{m,n}];
        if(m==1 && n==1) return 1;
        if(m==1) return dp[{m,n}] = uniquePaths(m,n-1);
        if(n==1) return dp[{m,n}] = uniquePaths(m-1,n);
        return dp[{m,n}] = uniquePaths(m,n-1) + uniquePaths(m-1,n);
    }
};