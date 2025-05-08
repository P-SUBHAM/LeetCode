// Approach 1: Priority queue based Graph traversal
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> vis(m,vector<int>(n,false)); // vis necessary 132ms else TLE
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0,0});
        auto valid = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n;
        };
        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            auto wt = node[0], i = node[1], j = node[2], c = node[3];
            if(vis[i][j]) continue; 
            vis[i][j] = true;
            // cout<<wt<<" "<<i<<" "<<j<<endl;
            if(i == m-1 && j == n-1) return wt;
            for(auto dir: dirs) {
                int x = i+dir[0], y = j+dir[1];
                if(valid(x,y) && !vis[x][y]) {
                    int new_wt = (1+(i+j)%2)+max(wt,moveTime[x][y]);//odd or even index
                    pq.push({new_wt,x,y});
                }
            }
        }
        return 0;
    }
};