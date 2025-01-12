// Approach 1: based on row parity iter from l or r // j = (n-2)|1 j is always odd
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(i%2 == 0) {
                for(int j = 0; j < n; j+=2) {
                    ans.push_back(grid[i][j]);
                }
            }
            else {
                for(int j = (n-2)|1; j >= 0; j-= 2) {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;
    }
};