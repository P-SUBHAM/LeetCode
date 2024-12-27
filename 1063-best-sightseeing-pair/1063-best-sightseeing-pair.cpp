class Solution {
public:
    // can be broken into (v[i] + i) + (v[j] - j)
    // calc prefixMax from left for v[i] + i, postfixMax from right for v[j] - j
    // as i < j
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> prefixmaxi = values;
        vector<int> postfixmaxj = values;
        // prefixMax for v[i] + i
        for(int i = 1; i < n; i++) {
            prefixmaxi[i] = max(prefixmaxi[i] + i, prefixmaxi[i-1]);
        }
        // cout<<"PrefixMax:"; for(auto it: prefixmaxi) {cout<<it<<" ";}; cout<<endl;
        // postfixmax for v[j] - j
        postfixmaxj[n-1] -= (n - 1);
        for(int j = n - 2; j >= 0; j--) {
            postfixmaxj[j] = max(postfixmaxj[j] - j, postfixmaxj[j+1]);
        }
        // cout<<"PostfixMax:"; for(auto it: postfixmaxj) {cout<<it<<" ";}; cout<<endl;
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, prefixmaxi[i] + postfixmaxj[i+1]);
        }
        return ans;
    }
};