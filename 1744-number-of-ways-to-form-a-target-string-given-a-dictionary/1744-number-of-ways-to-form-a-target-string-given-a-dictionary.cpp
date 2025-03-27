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
    int dpfIter2arr(string &target, int i, int n,
    vector<map<char,int>> &charFreq, int j, int m, vector<vector<int>> &dpNot) {
        vector<int> next(m+1,1);
        vector<int> curr(m+1);
        long long mod = 1e9+7;
        for(int i = n-1; i >= 0; i--) {
            curr[m] = 0; char ch = target[i];
            for(int j = m-1; j >= 0; j--) {
                int take = 0, notTake = 0;
                if(charFreq[j][ch] > 0) {
                    take = (1LL*charFreq[j][ch]*next[j+1])%mod;
                }
                notTake = (1LL*curr[j+1])%mod;
                curr[j] = (1LL*take+notTake)%mod;
            }
            next = curr;
        }
        return next[0];
    }
    int dpfIter1arr(string &target, int i, int n,
    vector<map<char,int>> &charFreq, int j, int m, vector<vector<int>> &dpNot) {
        vector<int> dp(m+1,1);
        long long mod = 1e9+7;
        int nextj1 = 0;
        for(int i = n-1; i >= 0; i--) {
            nextj1 = dp[m];
            dp[m] = 0; char ch = target[i];
            for(int j = m-1; j >= 0; j--) {
                int take = 0, notTake = 0;
                int temp = dp[j];
                if(charFreq[j][ch] > 0) {
                    take = (1LL*charFreq[j][ch]*nextj1)%mod;
                }
                notTake = (1LL*dp[j+1])%mod;
                dp[j] = (1LL*take+notTake)%mod;
                nextj1 = temp;
            }
        }
        return dp[0];
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
        // ans = dpf(target,0,n,charFreq,0,m,dp);
        ans = dpfIter1arr(target,0,n,charFreq,0,m,dp);
        return ans;
    }
};