// Approach 1: DP
// Base is longest increasing subsequence
class Solution {
public:
    int lis(vector<vector<int>>& envelopes, int i, int n, vector<int> &dp) {
        if(i == n-1) return 1;
        if(i >= n) return 0;
        int ans = 1;
        if(dp[i]!=-1) return dp[i];
        for(int j = i+1; j < n; j++) {
            if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]) {
                ans = max(ans,1+lis(envelopes,j,n,dp));
            }
        }
        return dp[i] = ans;
    }
    // once sorted by width, form lis on height
    int patienceSort(vector<vector<int>>& envelopes, int n) {
        auto comp = [&](vector<int> v1, vector<int> v2) { // imp
            if(v1[0]!=v2[0]) return v1[0] < v2[0];
            return v1[1] > v2[1]; // tackle same width then dec h to avoid lis involve
        };
        sort(envelopes.begin(), envelopes.end(),comp);
        multiset<int> mst;
        for (int i = 0; i < n; i++) {
            int h = envelopes[i][1];
            auto it = mst.lower_bound(h);
            if (it == mst.end()) mst.insert(h);
            else {
                mst.erase(it);
                mst.insert(h);
            }
        }
        return mst.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = 0, n = envelopes.size();
        ans = patienceSort(envelopes,n);
        return ans;
    }
};