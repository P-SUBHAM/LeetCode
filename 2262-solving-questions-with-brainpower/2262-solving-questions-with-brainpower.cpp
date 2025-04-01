// Approach 1: DP Memoization
class Solution {
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