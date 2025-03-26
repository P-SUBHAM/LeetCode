class Solution {
public:
    int timer = 1;
    void tarzanBridge(vector<vector<int>> &adj, int node, int parent,
    vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges) {
        tin[node] = low[node] = timer; timer++;
        for(auto nei: adj[node]) {
            if(nei == parent) continue; // Most Imp

            if(tin[nei] == -1) {//not vis then do dfs of neighbour
                // node -- nei
                tarzanBridge(adj, nei, node, tin, low, bridges);

                // if nei cant be visited faster than current parent node, that means this must be a bridge to next scc as p has to come first
                // > for 1 extra bridge that we need to cross to reach nei, = means same comp
                if(low[nei] > tin[node]) { // only > and ! >= bcs 0-1-2-0 all will have 0 as low but same comp and not bridge
                    // cout<<node<<"-"<<nei<<endl;
                    bridges.push_back({node,nei});
                }
            }
            low[node] = min(low[node],low[nei]); // to be updated either way(!! and skipped for parent)
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n);
        for(auto edges: connections) {
            int u = edges[0], v = edges[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n,-1); // use as visited array too
        vector<int> low(n);

        vector<vector<int>> bridges;
        tarzanBridge(adj,0,-1,tin,low,bridges);
        return bridges;
    }
};