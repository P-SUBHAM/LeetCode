class Solution {
public:
    map<int,int> dp;
    int help(vector<int> &nums, int i) {
        if(dp.find(i) != dp.end()) {
            return dp[i];
        }
        int ans = 1;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                ans = max(ans, 1 + help(nums,j));
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        int ans = help(nums,0);
        for(int i = 1; i < N; i++) {
            ans = max(ans, help(nums,i));
        }
        return ans;
    }
};