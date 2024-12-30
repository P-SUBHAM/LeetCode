// Aproach 1: Use memoized recursion to count all valid strings starting from 0 by adding zero and one steps while ensuring they fall within the range [low, high].
int MOD7 = 1e9+7;

class Solution {
public:
    int l,h,z,o;
    vector<int> dp;
    int countGoodStringsf(int x) {
        // cout<<x<<endl;
        if(x > h) {
            return 0;
        }
        if(dp[x] != -1) {
            return dp[x];
        }
        if(x >= l) {
            return dp[x] = (1 + countGoodStringsf(x+z) + countGoodStringsf(x+o))%MOD7;
        }
        return dp[x] = (countGoodStringsf(x+z) + countGoodStringsf(x+o))%MOD7;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        dp.clear();
        dp.resize(high+1,-1);
        l = low, h = high, z = zero, o = one;
        ans = countGoodStringsf(0);
        return ans;
    }
};