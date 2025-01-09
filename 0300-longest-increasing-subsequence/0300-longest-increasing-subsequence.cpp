class Solution {
public:
    vector<int> dp;
    int dpf(vector<int>& nums, int i) { // LIS at i incl nums[i]
        int ans = 1;
        if(dp[i] != -1) {return dp[i];}
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                ans = max(ans,1+dpf(nums,j));
            }
        }
        return dp[i] = ans;
    } 
    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size(),-1);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans,dpf(nums,i));
        }
        return ans;
    }
};