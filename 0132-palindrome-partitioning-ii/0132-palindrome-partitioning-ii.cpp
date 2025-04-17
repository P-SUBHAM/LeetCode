// Approach 1: Dp
// keep checking palindrom epossible, once pallindrom found increase partition and call for i+1
class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        for(int k = 0; k <= (j-i)/2; k++) {
            if(s[i+k] != s[j-k]) return false;
        }
        return true;
    }
    int dpf(string &s, int i,vector<int> &dp) {
        int n = s.size(), ans = n;
        if(i == n-1 || i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j = i; j < n; j++) {
            if(isPalindrome(s,i,j)) {
                if(j == n-1) return dp[i] = 0;
                ans = min(ans, 1 + dpf(s,j+1,dp));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return dpf(s,0,dp);
    }
};