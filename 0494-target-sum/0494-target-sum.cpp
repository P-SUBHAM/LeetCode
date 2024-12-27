class Solution {
public:
    int findTargetSumWaysf(vector<int> &nums, int target, int ind) {
        int n = nums.size();
        if(ind == n - 1) {
            if(target == nums[ind] or target == -1*nums[ind]) {
                if(nums[ind] == 0) {
                    return 2;
                }
                return 1;
            }
            return 0;
        }
        return findTargetSumWaysf(nums,target-nums[ind],ind+1) + findTargetSumWaysf(nums,target+nums[ind],ind+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWaysf(nums,target,0);
    }
};