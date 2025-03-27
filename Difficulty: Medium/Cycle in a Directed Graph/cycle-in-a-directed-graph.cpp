//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // return true if cycle present
    bool dfsc(vector<vector<int>> &adj, int n, int src, 
    vector<bool> &vis, vector<bool> &st) {
        vis[src] = st[src] = true;
        for(auto nei: adj[src]) {
            if(st[nei]) return true;
            if(!vis[nei]) {
                bool cyc = dfsc(adj,n,nei,vis,st);
                if(cyc) return true;
            }
        }
        st[src] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> vis(n);
        vector<bool> st(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bool cyc = dfsc(adj,n,i, vis, st);
                if(cyc) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends