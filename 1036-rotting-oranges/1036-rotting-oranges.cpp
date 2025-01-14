// Approach 1: Use BFS to find nearest rotten orange
class Solution {
public:
    int ans, m, n; // global
    vector<pair<int,int>> nextcoorf(vector<vector<int>>& grid, int x, int y) { // return valid neighbors
        vector<pair<int,int>> dir;
        if(x < 0 or x >= m or y < 0 or y >= n) return dir;
        if(0 <= x+1 && x+1 < m && grid[x+1][y] != 0) dir.push_back({x+1,y});
        if(0 <= x-1 && x-1 < m && grid[x-1][y] != 0) dir.push_back({x-1,y});
        if(0 <= y+1 && y+1 < n && grid[x][y+1] != 0) dir.push_back({x,y+1});
        if(0 <= y-1 && y-1 < n && grid[x][y-1] != 0) dir.push_back({x,y-1});
        return dir;
    }
    // dist to nearest Rotten orange
    int bfs(vector<vector<int>>& grid, int x, int y) { 
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<vector<int>> qu; // x,y,dist
        qu.push({x,y,0}); vis[x][y] = true; 
        while(!qu.empty()) {
            vector<int> ele = qu.front(); qu.pop();
            int i = ele[0], j = ele[1], d = ele[2];
            if(grid[i][j] == 2) return d;
            vector<pair<int,int>> nextcoord = nextcoorf(grid,i,j); // use proper coor i,j not x,y
            for(auto it: nextcoord) {
                if(!vis[it.first][it.second]) {
                    vis[it.first][it.second] = true;
                    qu.push({it.first,it.second,d+1});
                }
            }
        }
        return INT_MAX;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                if(grid[i][j] == 2) continue;
                if(grid[i][j] == 1) {
                    ans = max(ans,bfs(grid,i,j));
                }
            }
        }
        vector<pair<int,int>> dir = nextcoorf(grid,0,0);
        for(auto it: dir) {
            cout<<it.first<<" "<<it.second<<endl;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};