// Approach 1: Graph Cycle Detection in Directed Graph
// Vis all unvisit nodes and check cycle present or not
// maintain a current recursion stack vis and check

class Solution {
public:
    vector<vector<int>> adj;
    bool is_cycle(int src, vector<bool> &vis,vector<bool> &stack) {
        if(vis[src]) return stack[src];
        vis[src] = true;
        stack[src] = true; // maintain recursion stack
        for(auto nei: adj[src]) {
            if(stack[nei]) {
                return stack[src];
            }
            if(!vis[nei]) {
                if(is_cycle(nei,vis,stack)) {
                    return stack[src];
                }
            }
        }
        stack[src] = false; // if valid and no cycle(then not present in stack) , if in stack meaning its cycle forming
        return stack[src]; // return no cycle
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph;
        vector<bool> vis(n,false);
        vector<bool> stack(n,false);
        for(int i = 0; i < n; i++) {
            is_cycle(i,vis,stack);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!stack[i]) {
                ans.push_back(i);
            }
        }
        for(auto it: stack) cout<<it<<" "; cout<<endl;
        for(auto it: vis) cout<<it<<" "; cout<<endl;
        return ans;
    }
};

class Solution5 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> vis(n, 0); // 0->!vis 1->vis&nocycle 2->cycle
        vector<int> stack(n, 0);
        vector<int> cycle(n,0);
        function<bool(int)> is_cycle = [&](int node) { // return if cycle
            if(vis[node]) return cycle[node];
            // if(stack[node]) return cycle[node] = 1;
            vis[node] = 1; stack[node] = 1;
            for(auto nei: graph[node]) {
                if(!vis[nei] && is_cycle(nei)) {
                    return cycle[node] = 1;
                }
                if(stack[nei]) {
                    return cycle[node] = 1;
                }
            }
            stack[node] = 0; // removed from stack only if valid
            return cycle[node] = 0;
        };
        for (int i = 0; i < n; i++) {
            if (!is_cycle(i)) res.push_back(i);
        }
        for(auto it: cycle) cout<<it<<" ";
        return res;
    }
};

class Solution4 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> visited(n, 0);
        vector<int> inStack(n, 0);
        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return false;
            if (visited[node] == 2) return true;
            visited[node] = 1;
            for (int nei : graph[node]) {
                if (!dfs(nei)) {
                    visited[node] = 0; 
                    return false;
                }
            }
            visited[node] = 2;  
            return true;
        };
        for (int i = 0; i < n; i++) {
            if (dfs(i)) result.push_back(i);
        }
        return result;
    }
};

class Solution3 {
public:
    vector<vector<int>> adj;

    bool is_cycle(int src, vector<bool> &vis,vector<bool> &stack,vector<bool> &cycle) {
        if(vis[src]) return cycle[src];
        vis[src] = true;
        stack[src] = true; // maintain recursion stack
        for(auto nei: adj[src]) {
            if(!vis[nei]) {
                if(is_cycle(nei,vis,stack,cycle)) {
                    return cycle[nei] = true;
                }
            }
            if(stack[nei]) {
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

class Solution2 {
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
                    // stack[src] = false;
                    return cycle[nei] = true;
                }
            }
            if(stack[nei]) {
                vis[src] = false;
                // stack[src] = false;
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

class Solution1 {
public:
    vector<vector<int>> adj;
    bool is_cycle(int src, vector<bool> &vis,vector<bool> &stack,vector<bool> &cycle) {
        if(vis[src]) return cycle[src];
        vis[src] = true;
        stack[src] = true; // maintain recursion stack
        for(auto nei: adj[src]) {
            if(!vis[nei]) {
                if(is_cycle(nei,vis,stack,cycle)) {
                    vis[src] = false; // mark both vis and stack as false
                    stack[src] = false;
                    return cycle[nei] = true;
                }
            }
            if(stack[nei]) {
                vis[src] = false; // mark both vis and stack as false
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