// Approach 1: ans = global(a[i] - minv) (from left)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minv = prices[0], n = prices.size();
        for(int i = 1; i < n; i++) {
            ans = max(ans,prices[i] - minv);
            minv = min(minv,prices[i]);
        }
        return ans;
    }
};