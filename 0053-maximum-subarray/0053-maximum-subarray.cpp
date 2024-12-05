class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ans is global curr is local
        // cur is sum from last subarray, if -ve wont contribute in future so drop
        // initially if cursum - -ve adjust
        int ans = nums[0], currsum = max(0,nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            currsum += nums[i];
            ans = max(ans,currsum);
            if(currsum < 0) {
                currsum = 0;
            }
        }
        return ans;
    }
};