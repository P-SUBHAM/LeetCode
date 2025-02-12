// Approach 1: DP memoiation
// if ij == 1 then check for i+1,j; i,j+1; and the unintersected area
class Solution {
public:
    int cnt = 0;
    vector<vector<int>> dp;
    int dpf(vector<vector<char>>& matrix, int i, int j) {
        cnt++;
        int m = matrix.size(), n = matrix[0].size();
        if(i>=m||j>=n||i<0||j<0) return 0; // invalid coor
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]=='0') return dp[i][j] = 0; // if 0
        int l = dpf(matrix,i+1,j), h = dpf(matrix,i,j+1);
        if(l > h) swap(l,h);
        if(h != l) {
            return dp[i][j] = 1 + l;
        }
        return dp[i][j] = l + (matrix[i+l][j+l]=='1'?1:0); // + has higher preceedence than == so l+mat.. was being calculated first
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mat(m,vector<int> (n));
        dp.clear(); dp.resize(m,vector<int> (n,-1));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // if(matrix[i][j]==0) continue;
                int x = dpf(matrix,i,j); mat[i][j] = x;
                ans = max(ans,x);
            }
        }
        // for(auto row: mat) {
        //     for(auto it: row) {
        //         cout<<it<<" ";
        //     } cout<<endl;
        // }
        // cout<<endl<<"cnt:"<<cnt<<endl;
        return ans*ans;
    }
};