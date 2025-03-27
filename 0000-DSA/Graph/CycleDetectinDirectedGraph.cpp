class Solution {
  public:
    bool cycle;
    vector<bool> vis;
    vector<bool> stck;
    int n;
    void dfsc(vector<vector<int>>& adj, int node) {
        vis[node] = true;
        stck[node] = true;
        for(auto it: adj[node]) {
            if(vis[it]) {
                if(stck[it]) {
                    cycle = true; return;
                }
            }
            else {
                dfsc(adj,it);
            }
        }
        stck[node] = false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        n = V;
        cycle = false;
        vis.clear(); vis.resize(n,false);
        stck.clear(); stck.resize(n,false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfsc(adj,i);
            }
            if(cycle) {
                break;
            }
        }
        return cycle;
    }
};
