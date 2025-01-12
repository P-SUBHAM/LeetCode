// Approach 1: DP Memoization
// 3D dp
class Solution {
public:
    int m,n;
    vector<vector<int>> coin;
    vector<vector<vector<int>>> dp;
    int dpf(int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            int x = coin[i][j];
            if(neu > 0 && x < 0) {
                x = 0;
            }
            return x;
        }
        if(dp[i][j][neu] != INT_MIN) {
            return dp[i][j][neu];
        }
        if(j == n-1) {
            if(neu > 0 && coin[i][j] < 0) {
                return dp[i][j][neu] = max(coin[i][j]+dpf(i+1,j,neu),dpf(i+1,j,neu-1));
            }
            return dp[i][j][neu] = coin[i][j] + dpf(i+1,j,neu);
        }
        if(i == m-1) {
            if(neu > 0 && coin[i][j] < 0) {
                return dp[i][j][neu] = max(coin[i][j]+dpf(i,j+1,neu),dpf(i,j+1,neu-1));
            }
            return dp[i][j][neu] = coin[i][j] + dpf(i,j+1,neu);
        }
        if(neu > 0 && coin[i][j] < 0) {
            return dp[i][j][neu] = max(coin[i][j] + max(dpf(i,j+1,neu),dpf(i+1,j,neu)),max(dpf(i,j+1,neu-1),dpf(i+1,j,neu-1)));
        }
        return dp[i][j][neu] = coin[i][j] + max(dpf(i,j+1,neu),dpf(i+1,j,neu));
    }
    int maximumAmount(vector<vector<int>>& coins) {
        coin = coins;
        m = coins.size(); n = coins[0].size();
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(3,INT_MIN)));
        return dpf(0,0,2);
    }
};