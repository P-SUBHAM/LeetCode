// Approach 2: Dp Iterative
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        for(int j = 0; j <= n2; j++) // init
            prev[j] = j; 
        // for(int i = 0; i <= n1; i++) // init
        //     dp[i][0] = i;
        for(int i = 1; i <= n1; i++) {
            curr[0] = i; // imp
            for(int j = 1; j <= n2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    // dp[i][j] = dp[i-1][j-1];
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min({prev[j],curr[j-1],prev[j-1]});
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};

// Approach 1: DP recursive
class Solution1 {
public:
    int dpf(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 0;
        if(i == 0 || j == 0) return max(i,j);
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]) {
            return dp[i][j] = dpf(word1,word2,i-1,j-1,dp);
        }
        int insert = 1 + dpf(word1,word2,i,j-1,dp);
        int exchange = 1 + dpf(word1,word2,i-1,j-1,dp);
        int deletev = 1 + dpf(word1,word2,i-1,j,dp);
        return dp[i][j] = min({insert,exchange,deletev});
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int x = dpf(word1,word2,n1,n2,dp);
        // cout<<x<<endl;
        return x;
    }
};