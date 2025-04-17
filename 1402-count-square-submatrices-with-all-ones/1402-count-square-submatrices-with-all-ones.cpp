// Approach 1: tabular dp
// dp[i][j] = (mat[i][j]==1)?1:1 + min({matrix[i][j+1],matrix[i+1][j],matrix[i+1][j+1]}):0;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                matrix[i][j] = 
                (matrix[i][j]==1)?
                1 + min({matrix[i][j+1],matrix[i+1][j],matrix[i+1][j+1]}):
                0;
            }
        }
        int sum = 0;
        for(int i = 0; i < m; i++) {
            sum += accumulate(matrix[i].begin(),matrix[i].end(),0);
        }
        // for(auto row: matrix) {
        //     for(auto it: row) cout<<it<<" "; cout<<endl;
        // }
        return sum;
    }
};