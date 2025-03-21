//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        return shortestPathDijsktra(adj,src);
    }
    vector<int> shortestPathDijsktra(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n,1e9);
        dist[src] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq; pq.push({0,src});
        while(!pq.empty()) {
            auto v = pq.top(); pq.pop();
            int node = v[1], wt = v[0];
            for(auto it: adj[node]) {
                if(wt != 1e9 && wt + 1 < dist[it]) {
                    dist[it] = wt + 1;
                    pq.push({wt+1,it});
                }
            }
        }
        for(auto &it: dist) {
            if(it == 1e9) it = -1;
        }
        return dist;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends