class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src. // pair<global_dist,node> // adj<node,wt>
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();vector<int> dist(n,1e9);dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            for(auto nei: adj[node.second]) {
                int u = node.second, v = nei.first, wt = nei.second;
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt; pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
