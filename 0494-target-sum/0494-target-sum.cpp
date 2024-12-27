class Solution {
public:
    // APPROACH-2
    // DP using memoization
    map<pair<int,int>,int> dp;
    int findTargetSumWaysf(vector<int> &nums, int target, int ind) {
        int n = nums.size();
        if(ind == n - 1) {
            if(target == nums[ind] or target == -1*nums[ind]) {
                if(nums[ind] == 0) {
                    return dp[{target,ind}] = 2;
                }
                return dp[{target,ind}] = 1;
            }
            return dp[{target,ind}] = 0;
        }
        if(dp.find({target,ind})!=dp.end()) {
            return dp[{target,ind}];
        }
        return dp[{target,ind}] = findTargetSumWaysf(nums,target-nums[ind],ind+1) + findTargetSumWaysf(nums,target+nums[ind],ind+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return findTargetSumWaysf(nums,target,0);
    }
};