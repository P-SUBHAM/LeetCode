// Approach 2: DP Iterative
class Solution {
public:
    // dp[i] = max(a[i][0]+dp[i+1+a[i][1]],dp[i+1]);
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n,-1);
        for(int i = n-1; i >= 0; i--) {
            long long take = q[i][0];
            if(i+1+q[i][1] < n) take += dp[i+1+q[i][1]];
            long long notTake = 0;
            if(i+1 < n) notTake += dp[i+1];
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};

// Approach 1: DP Memoization
class Solution1 {
public:
    long long dpf(vector<vector<int>>& questions, int i, int n, vector<long long> &dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long take = questions[i][0] + dpf(questions,i+1+questions[i][1],n,dp);
        long long notTake = dpf(questions,i+1,n,dp);
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return dpf(questions,0,n,dp);
    }
};