// Approach 1: MultiSource BFS from water cell to find distance of land from nearest water
class Solution {
public:

    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        queue<vector<int>> qu;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    qu.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        function<bool(int,int)> valid = [&](int r, int c) {
            return 0 <= r && r < m && 0 <= c && c < n && !vis[r][c];
        };
        vector<vector<int>> res(m,vector<int>(n,0));
        while(!qu.empty()) {
            vector<int> v = qu.front(); qu.pop();
            int v_x = v[0];
            int v_y = v[1];
            int v_d = v[2];
            res[v_x][v_y] = v_d; // set dist from water, update here only
            for(auto dir: dirs) {
                int n_x = v_x + dir[0];
                int n_y = v_y + dir[1];
                int n_d = v_d + 1;
                // cout<<v_x<<":"<<v_y<<" ";
                if(valid(n_x,n_y)) {
                    qu.push({n_x,n_y,n_d});
                    vis[n_x][n_y] = true;
                }
            }
        }
        return res;
    }
};