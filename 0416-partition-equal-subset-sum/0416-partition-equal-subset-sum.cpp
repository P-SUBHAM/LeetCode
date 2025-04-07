// Approach 1: DP memoization subset sum problem
class Solution {
public:
    bool dpf(vector<int>& nums, int i, int sum, vector<vector<int>> &dp) {
        if(i == 0) {
            return nums[i] == sum;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = false;
        if(nums[i] <= sum) {
            take = dpf(nums,i-1,sum-nums[i],dp);
        }
        bool notTake = dpf(nums,i-1,sum,dp);
        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int subSum = sum/2;
        vector<vector<int>> dp(n, vector<int>(subSum+1,-1));
        return dpf(nums,n-1,subSum,dp);
    }
};