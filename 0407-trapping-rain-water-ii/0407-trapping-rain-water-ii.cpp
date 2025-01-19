// Approach 1: BFS+pq
// Start with outer edge into pq, as water = 0
// keep visiting smallest h from pq, update maxh, if nei h < maxh ans += diff
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int m = heightMap.size(), n = heightMap[0].size(), maxh = 0, ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(i == 0 or i == m-1 or j == 0 or j == n-1) {
                    pq.push({heightMap[i][j],i,j}); // push boundary into pq
                    heightMap[i][j] = -1; // mark vis by -1
                }
        while(!pq.empty()) {
            auto c = pq.top(); pq.pop(); int h = c[0];
            maxh = max(maxh,h); // maxh = max height among boundary explored
            ans += maxh - h; // if new cell has lower h than maxh ans+=diff
            for (auto dir: dirs) {
                int x = c[1] + dir[0], y = c[2] + dir[1]; // nei coor
                if(valid(x,y,m,n)&&heightMap[x][y]!=-1) { // valid and not vis
                    pq.push({heightMap[x][y],x,y}); heightMap[x][y] = -1; // mark vis
                }
            }
        }
        return ans;
    }
};