// Approach 1: using inplace modif to encode cnt using row0 or col0
// add +10 to encode count of comp, %10 will result if comp is present
// R0 C0 C1 C2
//    R1
//    R2 
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, r0 = 0; // for row 0
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) { // encode info by +10
                    if(i!=0)
                        grid[i][0] += 10;
                    else
                        r0 += 10;
                    grid[0][j] += 10;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]%10 == 1) {
                    if(i == 0) { // row
                        if(r0/10 > 1 or grid[0][j]/10 > 1) {
                            ans++;
                        }
                    }
                    else {
                        if(grid[0][j]/10 > 1 or grid[i][0]/10 > 1) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};