class Solution {
public:
    int dpf(vector<int>& prices, int i, int n, int t, vector<vector<int>> &dp) {
        if(t == 0 || i == n) {
            return 0;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int profit = 0;
        if(t%2==0) { // even so buy
            int take = 0, notTake = 0;
            take = -1*prices[i] + dpf(prices,i+1,n,t-1,dp);
            notTake = dpf(prices,i+1,n,t,dp);
            profit = max(take,notTake);
        }
        else {
            int take = 0, notTake = 0;
            take = prices[i] + dpf(prices,i+1,n,t-1,dp);
            notTake = dpf(prices,i+1,n,t,dp);
            profit = max(take,notTake);
        }
        return dp[i][t] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return dpf(prices,0,n,4,dp);
    }
};

class SolutionOldTLE17Jan25 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0; // if u buy none
        vector<int> left(n,prices[0]);
        vector<int> right(n,prices[n-1]);
        for(int i = 1; i < n; i++) {
            left[i] = min(left[i-1],prices[i]);
        }
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(prices[i],right[i+1]);
        }
        for(int i = 1; i < n; i++) { // if u buy once
            ans = max(ans,prices[i]-left[i-1]);
        }
        for(int i = 1; i < n; i++) {
            ans = max(ans,prices[i]-left[i-1]+max(0,(i+2 < n) ? (right[i+2]-prices[i+1]):0));
        }
        return ans;
    }
};