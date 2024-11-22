class Solution {
public:
    vector<int> altBits(vector<int> v, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(1^v[i]);
        }
        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<vector<int>,int> count;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            vector<int> v = altBits(matrix[i],n);
            int x = ++count[matrix[i]];
            int y = ++count[v];
            ans = max(ans,max(x,y));
        }
        return ans;
    }
};