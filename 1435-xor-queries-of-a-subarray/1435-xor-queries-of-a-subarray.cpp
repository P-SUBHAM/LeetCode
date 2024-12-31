class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixxor; vector<int> ans;
        int n = arr.size();
        prefixxor.push_back(0);
        for(auto x: arr) {
            int v = prefixxor.back() ^ x;
            prefixxor.push_back(v);
        }
        for(auto q: queries) {
            int v = prefixxor[q[1]+1] ^ prefixxor[q[0]];
            ans.push_back(v);
        }
        return ans;
    }
};