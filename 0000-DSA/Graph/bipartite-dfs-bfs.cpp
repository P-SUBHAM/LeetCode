// Approach 1: Bipartite Check using 2 coloring method with recursive dfs
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> col;
    bool bipart;
    void dfscolour(int src, int colc) {
        col[src] = colc;
        for(auto nei: adj[src]) {
            if(col[nei]==-1) { // not vis ok - col it
                dfscolour(nei,col[src]^1); // set col[par]^1
            }
            else if(col[nei]!=col[src]^1) { // already col with othr col not bipart
                bipart = false;
            }
        }
    }
    void bfscolour(int src, int colc) {
        col[src] = colc;
        queue<int> qu;
        qu.push(src);
        while (!qu.empty()) {
            int node = qu.front(); qu.pop();
            for (int nei : adj[node]) {
                if (col[nei] == -1) {
                    col[nei] = 1^col[node]; // set col[par]^1
                    qu.push(nei);
                } else if (col[nei] != 1^col[node]) {
                    bipart = false;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        adj = graph, bipart = true; // assignment
        int n = graph.size(); // declaration
        col.resize(n,-1); // -1:unvis 0:col0 1:col1
        for(int i = 0; i < n; i++) {
            if(col[i]==-1) {
                // dfscolour(i,0);
                bfscolour(i,0);
            }
        }
        return bipart;
    }
};
