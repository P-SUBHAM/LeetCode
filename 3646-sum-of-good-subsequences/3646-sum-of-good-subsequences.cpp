// Approach 1: DP Counting technique
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int N = 1e5+2, n = nums.size();
        vector<long long> cnt(N,0);
        vector<long long> sum(N,0);
        long long totSum = 0;
        int mod = 1e9+7;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            long long cntplus = (((x-1>=0)?cnt[x-1]:0) + cnt[x+1] + 1)%mod;
            // cout<<cntplus<<endl;
            cnt[x] = (cnt[x]+ cntplus)%mod;
            sum[x] += (((x-1>=0)?sum[x-1]:0)+sum[x+1]+(1ll*(cntplus%mod) * x)%mod)%mod;
            sum[x] %= mod;
        }
        for(int i = 0; i < N; i++) {
            totSum = totSum + sum[i];
            totSum %= mod;
        }
        // for(int i = 0; i < 10; i++) cout<<cnt[i]<<" "; cout<<endl;
        // for(int i = 0; i < 10; i++) cout<<sum[i]<<" "; cout<<endl;
        return totSum;
    }
};