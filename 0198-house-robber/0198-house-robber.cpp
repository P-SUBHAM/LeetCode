class Solution {
public:
    map<int,int> dp;
    int solve(vector<int> &nums, int i, int j) {
        if(dp.find(i) != dp.end()) {
            return dp[i];
        }
        if(i == j) {
            return dp[i] = nums[i];
        }
        if(i+1==j) {
            return dp[i] = max(nums[i],nums[j]);
        }
        return dp[i] = max(nums[i]+solve(nums,i+2,j),solve(nums,i+1,j));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        return solve(nums,0,n-1);
    }
};