// Approach 1: HashMap
// keep iterating arr, mark (r,c)++ coloured, check if count=size
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), N = arr.size();
        vector<vector<int>> map_rc(m*n+1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                auto &v = map_rc[mat[i][j]];
                v.insert(v.end(), {i, j}); // use .insert(it,list) for inserting multiple elements at once
            }
        }
        vector<int> row_cnt(m,0), col_cnt(n,0);
        for(int i = 0; i < N; i++) {
            int r = map_rc[arr[i]][0], c = map_rc[arr[i]][1];
            cout<<r<<","<<c<<" ";
            row_cnt[r]++;
            col_cnt[c]++;
            if(row_cnt[r] == n or col_cnt[c] == m) { // row->n ,col->m cells=>alt
                return i;
            }
        }
        return N;
    }
};