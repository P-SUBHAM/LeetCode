// Approach 1 DP
class Solution {
public:
    int dpf(vector<int>& arr, int i, int k, vector<int> &dp) {
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int maxv = arr[i], ans = arr[i];
        for(int j = 1; j <= k && i-j+1 >= 0; j++) {
            maxv = max(maxv,arr[i-j+1]);
            ans = max(ans,maxv*j+dpf(arr,i-j,k,dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return dpf(arr,arr.size()-1,k,dp);
    }
};