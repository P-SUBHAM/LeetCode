// Approach 1: BFS from all water cell to add nei fishes, take global max
class Solution {
public:
    int ans,m,n; 
    vector<vector<int>> dirs = {{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int fish = grid[r][c];
        grid[r][c] = 0; // vis
        queue<vector<int>> qu;
        qu.push({r,c});
        while(!qu.empty()) {
            auto v = qu.front(); qu.pop();
            int x = v[0], y = v[1];
            for(auto dir: dirs) {
                int nx = x+dir[0], ny = y+dir[1];
                if(0<=nx&&nx<m && 0<=ny&&ny<n && grid[nx][ny]>0) {
                    fish += grid[nx][ny]; grid[nx][ny] = 0; // vis->push
                    qu.push({nx,ny});
                }
            }
        }
        ans = max(ans,fish);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) 
                    dfs(grid,i,j);
            }
        }
        return ans;
    }
};