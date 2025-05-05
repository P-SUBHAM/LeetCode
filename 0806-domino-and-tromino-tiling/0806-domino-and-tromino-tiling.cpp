// Approach 1: Bitmask DP Domino Tiling
class Solution {
public:
    static const int mod = 1e9+7;
    // 0 1 2 3 <- state \/ Domino filled
    // 0 1 0 1
    // 0 0 1 1
    vector<int> getNextBitMaskList(int bitmask) {
        vector<int> nextBitMaskList;
        if(bitmask == 0) {
            nextBitMaskList = {3,0,1,2};
        }
        else if(bitmask == 1) {
            nextBitMaskList = {2,3};
        }
        else if(bitmask == 2) {
            nextBitMaskList = {1,3};
        }
        else {
            nextBitMaskList = {0};
        }
        return nextBitMaskList;
    }
    int dpf(int i, int bitmask, int n,vector<vector<int>> &dp) {
        if(i == n) {
            return bitmask == 0; // no overflow condition
        }
        if(dp[bitmask][i] != -1) return dp[bitmask][i];
        int ans = 0;
        vector<int> nextBitMaskList = getNextBitMaskList(bitmask);
        for(auto nextBitMask: nextBitMaskList) {
            ans = (1ll*ans + dpf(i+1,nextBitMask,n,dp))%mod;
        }
        return dp[bitmask][i] = ans;
    }
    int numTilings(int n) {
        int bitmask = 0;
        vector<vector<int>> dp(1<<2,vector<int>(n,-1));
        return dpf(0,bitmask,n,dp);
    }
};