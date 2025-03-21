// Approach 1: Graph Traversal 
class Solution {
public:
    int ans,m,n;
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid, int r, int c) {
        stack<vector<int>> st;
        st.push({r,c}); grid[r][c] = 0;
        int cnt = 1;
        while(!st.empty()) {
            auto v = st.top(); st.pop();
            for(auto dir: dirs) {
                int x = v[0]+dir[0];
                int y = v[1]+dir[1];
                if(0<=x&&x<m&&0<=y&&y<n&&grid[x][y]==1) {
                    grid[x][y] = 0; cnt++;
                    st.push({x,y});
                }
            }
        }
        ans=max(ans,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]==1)
                    dfs(grid,i,j);
        return ans;
    }
};