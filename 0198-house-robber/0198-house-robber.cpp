class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        int n = nums.size();
        if(n == 1) return nums[0];
        dp[n-2] = max(dp[n-2],dp[n-1]);
        for(int i = n - 3; i >= 0; i--) {
            dp[i] = max(dp[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};