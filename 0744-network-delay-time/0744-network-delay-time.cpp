// Approach 1: Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        int inf = INT_MAX;
        vector<int> dist(n,inf); dist[src-1] = 0;
        for(int i = 0; i < n-1; i++) {
            for(auto edge: times) {
                int u = edge[0]-1, v = edge[1]-1, w = edge[2];
                if(dist[u] != inf) {
                    dist[v] = min(dist[v],dist[u]+w);
                }
            }
        }
        int ans = *max_element(dist.begin(),dist.end());
        return (ans == inf)? -1: ans;
    }
};