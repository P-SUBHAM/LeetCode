// Approach 1: Bipartite Check using 2 coloring method with recursive dfs
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> col;
    bool bipart;
    void dfscolour(int src, int colc) {
        col[src] = colc;
        colc^=1;
        for(auto nei: adj[src]) {
            if(col[nei]==-1) { // not vis ok - col it
                dfscolour(nei,colc);
            }
            else if(col[nei]!=colc) { // already col with othr col not bipart
                bipart = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        adj = graph, bipart = true; // assignment
        int n = graph.size(); // declaration
        col.resize(n,-1); // -1:unvis 0:col0 1:col1
        for(int i = 0; i < n; i++) {
            if(col[i]==-1) {
                dfscolour(i,0);
            }
        }
        return bipart;
    }
};