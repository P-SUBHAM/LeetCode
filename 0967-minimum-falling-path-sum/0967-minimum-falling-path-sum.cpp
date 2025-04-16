// Approach 1: Tabular DP
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(j == n-1) {
                    matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j-1]); 
                    continue;
                }
                if(j  == 0) {
                    matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j+1]); 
                    continue;
                }
                matrix[i][j] += min({matrix[i+1][j-1],matrix[i+1][j],matrix[i+1][j+1]});
            }
        }
        return *min_element(matrix[0].begin(),matrix[0].end());
    }
};