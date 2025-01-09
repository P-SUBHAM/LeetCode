// Approach 1 - memoization
// You can either take the coin or leave the coin and go for next coin denomination
class Solution {
public:
    map<pair<int,int>,int> dp;
    int dpf(int amount, vector<int>& coins, int i) {
        int n = coins.size();
        if(i == n) {
            return 0;
        }
        if(amount < 0) {
            return 0;
        }
        if(amount == 0) {
            return 1;
        }
        if(dp.find({amount,i})!=dp.end()) {
            return dp[{amount,i}];
        }
        return dp[{amount,i}] = (dpf(amount-coins[i],coins,i) + dpf(amount,coins,i+1));
    }
    
    int change(int amount, vector<int>& coins) {
        dp.clear();
        sort(coins.begin(), coins.end());
        int ans = dpf(amount, coins, 0);
        return ans;
    }
};