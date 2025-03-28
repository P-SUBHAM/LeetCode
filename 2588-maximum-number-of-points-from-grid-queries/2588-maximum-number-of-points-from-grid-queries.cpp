class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<bool>> &vis) {
        return i >= 0 && j >= 0 && i < m && j < n && !vis[i][j];
    }
    int minBfs (vector<vector<int>>& grid, int maxV, 
    priority_queue<vector<int>,vector<vector<int>>,greater<>> &minpq,
    vector<vector<bool>> &vis, int m, int n) {
        int cnt = 0;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!minpq.empty() && minpq.top()[0] < maxV) {
            auto pqNode = minpq.top(); minpq.pop(); cnt++;
            int v = pqNode[0], x = pqNode[1], y = pqNode[2];
            // cout<<v<<"-"<<cnt<<" "; // dbg
            for(auto dir: dirs) {
                int x_n = x + dir[0];
                int y_n = y + dir[1];
                if(isValid(x_n,y_n,m,n,vis)) {
                    minpq.push({grid[x_n][y_n],x_n,y_n});
                    vis[x_n][y_n] = true;
                }
            }
        } // cout<<endl;
        return cnt;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>> offlineQueries;
        int m = grid.size();
        int n = grid[0].size();
        int N = queries.size();
        for(int i = 0; i < N; i++) {
            int maxV = queries[i];
            int ind = i;
            offlineQueries.push_back({maxV,ind});
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        // {grid[i][j],i,j}
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minpq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<int> ans(N);
        int cnt = 0;
        minpq.push({grid[0][0],0,0}); vis[0][0] = true; // chk mark vis at init
        for(int i = 0; i < N; i++) {
            int maxV = offlineQueries[i][0];
            int ind = offlineQueries[i][1];
            int x = minBfs(grid,maxV,minpq,vis,m,n);
            cnt += x;
            // cout<<maxV<<":"<<x<<endl; // dbg
            ans[ind] = cnt;
        }
        return ans;
    }
};