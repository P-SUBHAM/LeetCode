class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int minv = arrays[0][0], maxv = arrays[0][arrays[0].size()-1];
        int res = 0;
        for(int i = 1; i < n; i++) {
            res = max(res,abs(arrays[i][arrays[i].size()-1] - minv));
            res = max(res,abs(maxv - arrays[i][0]));
            minv = min(minv,arrays[i][0]);
            maxv = max(maxv,arrays[i][arrays[i].size()-1]);
        }
        return res;
    }
};