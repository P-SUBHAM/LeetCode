// Approach 3: 0-1 BFS
// make edges from each node to neighbour with wt 0 or 1
// use 0-1 bfs if wt is 0 add at front else add at back
class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<vector<vector<int>>>> adj; // adj[i][j] = [[x1,y1,wt1],[],[]]
    int m,n,inf;
    void ZeroOneBFS() {
        dist[0][0] = 0;
        deque<pair<int,int>> dqu;
        dqu.push_back({0,0});
        while(!dqu.empty()) {
            pair<int,int> p = dqu.front(); dqu.pop_front();
            int i = p.first, j = p.second;
            for(auto it: adj[i][j]) {
                int x = it[0], y = it[1], w = it[2];
                if(dist[x][y] > dist[i][j] + w) {
                    dist[x][y] = dist[i][j] + w;
                    if(w == 0) {
                        dqu.push_front({x,y});
                    }
                    else {
                        dqu.push_back({x,y});
                    }
                }
            }
        }
    }
    void GraphEdgeF(int i, int j, int dir) {
        int wt = 1, w;
        if(i+1 < m) {
            w = wt;
            if(dir == 3) w = 0;
            adj[i][j].push_back({i+1,j,w});
        }
        if(0 <= i-1) {
            w = wt;
            if(dir == 4) w = 0;
            adj[i][j].push_back({i-1,j,w});
        }
        if(j+1 < n) {
            w = wt;
            if(dir == 1) w = 0;
            adj[i][j].push_back({i,j+1,w});
        }
        if(0 <= j-1) {
            w = wt;
            if(dir == 2) w = 0;
            adj[i][j].push_back({i,j-1,w});
        }
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), inf = 1e5;
        adj.clear(); adj.resize(m,vector<vector<vector<int>>>(n));
        dist.clear(); dist.resize(m,vector<int>(n,inf));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                GraphEdgeF(i,j,grid[i][j]);
            }
        }
        ZeroOneBFS();
        cout<<endl;
        // for(auto x: dist) {
        //     for(auto y: x) {
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }
        return dist[m-1][n-1];
    }
};


// Approach 2: Using Graph
// Shortest-path problem: each cell is node, and moving in dir: 0 cost, change dir: 1 cost. 
// Using a priority queue (BFS with Dijkstra-like algorithm) ensures the lowest-cost path is always explored first
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX)); // Min cost to reach each cell
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<int> dx = {0, 0, 1, -1}; // Directions: right, left, down, up
        vector<int> dy = {1, -1, 0, 0};

        pq.push({0, {0, 0}}); // {cost, {row, col}}
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [curCost, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if (x == m - 1 && y == n - 1) {
                return curCost; // Reached destination
            }

            if (curCost > cost[x][y]) {
                continue; // Skip if we've already found a cheaper path
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = curCost + (grid[x][y] != d + 1); // +1 if changing direction
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return -1; // Shouldn't reach here
    }
};

class Solution1 {
public:
    // Approach 1: Used DP (NOT-OPTIMAL VERSION)
    int m,n; int global_ans; // vector<vector<int>> grid;
    map<pair<pair<int,int>,vector<vector<bool>>>,int> dp;
    vector<int> neiF(int i, int j, vector<vector<bool>> vis) {
        vector<int> neipos;
        if(0 <= i+1 && i+1 <= m-1 && !vis[i+1][j]) {
            neipos.push_back(3);
        }
        if(0 <= j+1 && j+1 <= n-1 && !vis[i][j+1]) {
            neipos.push_back(1);
        }
        if(0 <= i-1 && i-1 <= m-1 && !vis[i-1][j]) {
            neipos.push_back(4);
        }
        if(0 <= j-1 && j-1 <= n-1 && !vis[i][j-1]) {
            neipos.push_back(2);
        }
        return neipos;
    }
    vector<int> coorF(int i, int j, int dir) {
        if(dir == 1) {
            return {i,j+1};
        }
        if(dir == 2) {
            return {i,j-1};
        }
        if(dir == 3) {
            return {i+1,j};
        }
        if(dir == 4) {
            return {i-1,j};
        }
        return {};
    }
    int dpF(vector<vector<int>> grid, int i, int j, vector<vector<bool>> vis) {
        if(i == m-1 && j == n-1) {
            return 0;
        }
        if(i < 0 or i >= m or j < 0 or j >= n) {
            return 1e5;
        }
        if(dp.find({{i,j},vis}) != dp.end()) {
            return dp[{{i,j},vis}];
        }
        int x = grid[i][j];
        vis[i][j] = true;
        vector<int> nei = neiF(i,j,vis);
        int ans = 1e5;
        for(auto it: nei) {
            if(it == x) {
                vector<int> coor = coorF(i,j,it);
                ans = min(ans,dpF(grid,coor[0],coor[1],vis));
            }
            else {
                vector<int> coor = coorF(i,j,it);
                ans = min(ans,1 + dpF(grid,coor[0],coor[1],vis));
            }
        }
        return dp[{{i,j},vis}] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.clear(); //dp.resize(m+1,vector<int> (n+1,-1));
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        int ans = dpF(grid,0,0,vis);
        // cout<<"ans:"<<ans<<endl;
        return ans;
    }
};