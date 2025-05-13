// Approach 1: Dynamic Programming
// ch != 'z' => dp[i][j] = dp[i+1][j-1]; 
// ch =='z' => dp[i][j] = (1ll*dp[0][j-1] + dp[1][j-1])%mod;
class Solution {
public:
    static const long long mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size(); 
        vector<vector<int>> dp(26,vector<int>(t+1,1));
        for(int j = 1; j <= t; j++) {
            for(int i = 0; i < 26; i++) {
                char ch = 'a' + i;
                if(ch != 'z') {
                    dp[i][j] = dp[i+1][j-1];
                }
                else {
                    dp[i][j] = (1ll*dp[0][j-1] + dp[1][j-1])%mod;
                }
            } 
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + dp[s[i]-'a'][t])%mod;
        }
        return ans;
    }
};