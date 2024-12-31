class Solution {
public:
    int n; vector<int> dp;
    int dpf(vector<int>& days, vector<int>& costs, int i) {
        int I = i;
        if(i >= days.size()) {
            return 0;
        }
        if(dp[i] != -1) {return dp[i];}
        int x = days[i];
        int oneday = costs[0] + dpf(days,costs,i+1);
        while(i < n && days[i] <= x + 6) {i++;}
        int sevday = costs[1] + dpf(days,costs,i);
        while(i < n && days[i] <= x + 29) {i++;}
        int mon = costs[2] + dpf(days,costs,i);
        return dp[I] = min({oneday,sevday,mon});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0; n = days.size(); dp.clear(); dp.resize(n+1,-1);
        ans = dpf(days,costs,0);
        return ans;
    }
};