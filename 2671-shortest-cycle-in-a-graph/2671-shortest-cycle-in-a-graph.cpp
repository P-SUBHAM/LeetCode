// Approach 1:finding shortest cycle length from each edge->global min
//1. Select an edge
//2. remove from adj list
//3. find shortest dist from u-v i.e shortest cycle length including that edge, BFS(as edge wt is same)
// 4. Repeast for all edges
//Finding All cycles in a graph is Non-Polynomial algo
class Solution {
public:
    int mincyclen, n;
    vector<set<int>> adj;
    void cycleLen(int src, int dest) { // bfs len from src to dest
        queue<vector<int>> qu; qu.push({src,0}); 
        vector<bool> vis(n,false); vis[src] = true;
        while(!qu.empty()) {
            auto tope = qu.front(); qu.pop();
            int node = tope[0], d = tope[1];
            if(node==dest) {
                mincyclen = min(mincyclen,d+1);
            }
            for(auto nei: adj[node]) {
                if(!vis[nei]) {
                    qu.push({nei,d+1}); vis[nei] = true;
                }
            }
        }
    }
    int findShortestCycle(int N, vector<vector<int>>& edges) {
        mincyclen = 1e8; n = N; adj.clear(); adj.resize(n); 
        for(auto e: edges) {
            int u = e[0], v = e[1];
            adj[u].insert(v); adj[v].insert(u);
        }
        for(auto e: edges) { // eth edge to incl and find min cycle len
            int u = e[0], v = e[1];
            adj[u].erase(v); adj[v].erase(u);
            cycleLen(u,v);
            adj[u].insert(v); adj[v].insert(u); 
        }
        return mincyclen==1e8?-1:mincyclen;
    }
};