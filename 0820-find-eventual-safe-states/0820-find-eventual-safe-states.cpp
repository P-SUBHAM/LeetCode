// Approach 1: Graph Cycle Detection in Directed Graph
// Vis all unvisit nodes and check cycle present or not
// maintain a current recursion stack vis and check
class Solution {
public:
    vector<vector<int>> adj;
    bool is_cycle(int src, vector<bool> &vis,vector<bool> &stack,vector<bool> cycle) {
        if(vis[src]) return cycle[src];
        vis[src] = true;
        stack[src] = true; // maintain recursion stack
        for(auto nei: adj[src]) {
            if(!vis[nei]) {
                if(is_cycle(nei,vis,stack,cycle)) {
                    vis[src] = false;
                    stack[src] = false;
                    return cycle[nei] = true;
                }
            }
            if(stack[nei]) {
                vis[src] = false;
                stack[src] = false;
                return cycle[nei] = true;
            }
        }
        stack[src] = false;
        return cycle[src] = false; // return no cycle
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph;
        vector<bool> vis(n,false);
        vector<bool> stack(n,false);
        vector<bool> cycle(n,false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cycle[i] = is_cycle(i,vis,stack,cycle);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!cycle[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};