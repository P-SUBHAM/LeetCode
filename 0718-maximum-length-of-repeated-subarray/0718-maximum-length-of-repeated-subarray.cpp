class Solution {
public:
    // Approach 1: DP (lca) 
    // use tabular dp dpij represent longest common subarray ending at ij
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int j = 1; j <= n; j++) {
            if(nums1[0] == nums2[j-1]) {
                dp[1][j] = 1; ans = 1;
            }
        }
        for(int i = 1; i <= m; i++) {
            if(nums2[0] == nums1[i-1]) {
                dp[i][1] = 1; ans = 1;
            }
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        // for(auto row: dp) {
        //     for(auto it: row) {
        //         cout<<it<<" ";
        //     }cout<<endl;
        // }
        return ans;
    }
};