// Approach 1: Dynamic Programming
// ch != 'z' => dp[i][j] = dp[i+1][j-1]; 
// ch =='z' => dp[i][j] = (1ll*dp[0][j-1] + dp[1][j-1])%mod;
class Solution {
public:
    static const long long mod = 1e9+7;
    static int dp[26][100001];
    static bool precompf;
    void precompute() {
        precompf = false;
        for (int i = 0; i < 26; i++)
            dp[i][0] = 1;
        for(int j = 1; j <= 100000; j++) {
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
    }
    int lengthAfterTransformations(string s, int t) {
        int n = s.size(); 
        if(precompf) {
            precompute();
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + dp[s[i]-'a'][t])%mod;
        }
        return ans;
    }
};

int Solution::dp[26][100001];
bool Solution::precompf = true;