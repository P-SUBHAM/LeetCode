// Approach 1: cycle detection in directed graph using dfs recursion stack
class Solution {
public:
    bool dfsCycleDir(vector<vector<int>> &adj, vector<int> &vis
    , int src) {
        vis[src] = 2; // vis and in rec stack
        for(auto nei: adj[src]) {
            if(vis[nei] == -1) {
                if(dfsCycleDir(adj,vis,nei)) return true;
            }
            else if(vis[nei] == 2) return true;
        }
        vis[src] = 1;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,-1);
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                if(dfsCycleDir(adj,vis,i)) return false;
            }
        }
        return true;
    }
};