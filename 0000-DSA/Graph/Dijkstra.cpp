class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src. // pair<global_dist,node> // adj<node,wt>
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
      int n = adj.size(); vector<int> dist(n+1,1e9);dist[src] = 0;
      priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
      pq.push({0,src});
      while(!pq.empty()) {
          auto v = pq.top(); pq.pop();
          int node = v[1], dis = v[0];
          if(dis != dist[node]) {continue;} // VIMP
          for(auto nei: adj[node]) {
              int u = node, v = nei[0], wt = nei[1];
              if(dist[v] > dist[u] + wt) {
                  dist[v] = dist[u] + wt; pq.push({dist[v],v});
              }
          }
      }
      return dist;
  }
};
