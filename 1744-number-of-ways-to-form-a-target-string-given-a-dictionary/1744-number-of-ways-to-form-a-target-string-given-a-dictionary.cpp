class Solution {
public:
    int dpf(string &target, int i, int n,
    vector<map<char,int>> &charFreq, int j, int m,vector<vector<int>> &dp) {
        if(i == n) { // target met already
            return 1;
        }
        if(j == m) { // still target not met
            return 0;
        }
        char ch = target[i];
        int take = 0, notTake = 0;
        long long mod = 1e9+7;
        if(dp[i][j] != -1) return dp[i][j];
        if(charFreq[j][ch] > 0) { // can take or skip
            take = (1LL*charFreq[j][ch]*dpf(target,i+1,n,charFreq,j+1,m,dp))%mod;
            notTake = (1LL*dpf(target,i,n,charFreq,j+1,m,dp))%mod;
        }
        else {
            notTake = (1LL*dpf(target,i,n,charFreq,j+1,m,dp))%mod;
        }
        return dp[i][j] = (1LL*take+notTake)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        int wordsLen = words.size();
        vector<map<char,int>> charFreq(m);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0; i < wordsLen; i++) {
            for(int j = 0; j < m; j++) {
                char ch = words[i][j];
                int index = j;
                charFreq[index][ch]++;
            }
        }
        int ans = 0;
        ans = dpf(target,0,n,charFreq,0,m,dp);
        return ans;
    }
};