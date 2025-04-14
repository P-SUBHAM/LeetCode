// Approach 1:
// iter n-1 times on all edges e (n-1 as max path n-1 edges)
// u v w min(dist[v],dist[u]+w)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    int n = V;
    vector<int> dist(n,1e8); dist[src] = 0; bool change = false;
    for(int i = 0; i < n; i++) {
        change = false;
        for(auto it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u]==1e8) continue; // inf - 4 ~ inf so skip
            if(dist[v] > dist[u] + wt) change = true;
            dist[v] = min(dist[v],dist[u] + wt);
        }
    }
    if(change) return {-1};
    return dist;
}
