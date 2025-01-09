// Apprpach 2: Tabular 2D
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<int> dp(amount+1,1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
                else {
                    break;
                }
            }
        }
        if(dp[amount] == 1e9) {return -1;}
        return dp[amount];
    }
};

// vector<int> dp;
// // Approach 1 memoization
// class Solution {
// public:
//     int dpf(vector<int>& coins, int amount) {
//         int n = coins.size(), ans = 1e9;
//         if(amount < 0) {return 1e9;}
//         if(amount == 0) {
//             return 0;
//         }
//         if(dp[amount] != 1e9) {
//             return dp[amount];
//         }
//         for(int i = 0; i < n; i++) {
//             if(amount-coins[i] >= 0) {
//                 ans = min(ans,1+dpf(coins,amount-coins[i]));
//             }
//         }
//         return dp[amount] = ans;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         dp.clear();
//         dp.resize(amount+1,1e9);
//         int ans = dpf(coins,amount);
//         if(ans == 1e9) {
//             return -1;
//         }
//         else {
//             return ans;
//         }
//     }
// };