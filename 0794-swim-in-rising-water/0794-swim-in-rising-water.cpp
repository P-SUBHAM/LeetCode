// Approach 1: Priority_queue based traversal
// you have to reach src-dest via lowest max height
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0, n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq; // minpq
        pq.push({grid[0][0],0,0}); vis[0][0] = true;
        function<bool(int,int,int)> isValid = [&](int i, int j, int n)->bool {
            return i >= 0 && j >= 0 && i < n && j < n && !vis[i][j];
        };
        while(!pq.empty()) {
            auto pqnode = pq.top(); pq.pop();
            int w = pqnode[0], i = pqnode[1], j = pqnode[2];
            ans = max(ans,w);
            if(i == n-1 && j == n-1) return ans;
            for(auto dir: dirs) {
                int i_n = i + dir[0];
                int j_n = j + dir[1];
                if(isValid(i_n,j_n,n)) {
                    pq.push({grid[i_n][j_n],i_n,j_n});
                    vis[i_n][j_n] = true;
                }
            }
        }
        return ans;
    }
};