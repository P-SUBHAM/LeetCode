// Approach 1: DP memoization
// Invert Always Inverts
// Instead of deciding which balloon to pop first and then continue 
// We can think which balloon to pop last, and decide on that 
class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;
    int dpf(int l, int r) {
        if(l > r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for(int i = l; i <= r; i++) {
            int x = arr[l-1]*arr[i]*arr[r+1];
            x += dpf(l,i-1) + dpf(i+1,r);
            ans = max(ans,x);
        }
        // cout<<" l:"<<l<<" r:"<<r;
        // cout<<" a:"<<ans<<endl;
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        arr = nums;
        arr.push_back(1);
        arr.insert(arr.begin(),{1});
        // for(auto it: arr) cout<<" "<<it;
        int l = 1, n = arr.size(), r = n-2;
        dp.resize(n,vector<int>(n,-1));
        return dpf(l,r);
    }
};