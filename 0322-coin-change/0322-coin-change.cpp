// Approach 1 memoization
class Solution {
public:
    map<int,int> dp;
    int dpf(vector<int>& coins, int amount) {
        int n = coins.size(), ans = 1e9;
        if(amount < 0) {return 1e9;}
        if(amount == 0) {
            return 0;
        }
        if(dp.find(amount) != dp.end()) {
            return dp[amount];
        }
        for(int i = 0; i < n; i++) {
            if(amount-coins[i] >= 0) {
                ans = min(ans,1+dpf(coins,amount-coins[i]));
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = dpf(coins,amount);
        if(ans == 1e9) {
            return -1;
        }
        else {
            return ans;
        }
    }
};