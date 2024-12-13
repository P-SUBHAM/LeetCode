class Solution {
public:
    vector<vector<bool>> vis;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    int m, n;
    bool valid(int i, int j) {
        if(0 <= i && i < m && 0 <= j && j < n) {
            return true;
        }
        return false;
    }
    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int,int>> qu;
        qu.push({i,j});
        vis[i][j] = true;
        while(!qu.empty()) {
            pair<int,int> coord = qu.front(); qu.pop();
            int i = coord.first;
            int j = coord.second;
            for(auto dv: dir) {
                int x = i + dv.first;
                int y = j + dv.second;
                if(valid(x,y) && !vis[x][y] && grid[x][y] == '1') {
                    // Mark as visited when enqueued: Prevents multiple enqueues of the same cell by marking it as visited immediately upon enqueueing.
                    qu.push({x,y});
                    vis[x][y] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool> (n, false));
        int count = 0;
        // itterate map, if 1 found do bfs and visit all island ele; IslandCount++
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // if 0 or (1 & already visited) skip
                if(grid[i][j] == '1' && !vis[i][j]) {
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout<<vis[i][j]<<" ";
        //     }cout<<endl;
        // }
        return count;
    }
};