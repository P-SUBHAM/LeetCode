//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    // Prims - Algorithm T: O(V + E)logV S:O(V+E)
    // Prim works for undirected as MST exist, for directed it differs
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> dist;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        dist.clear(); dist.resize(V,1e9);
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0});
        int ans = 0;
        vector<bool> vis(V,false);
        // vis array required to make sure one node incl in MStree during pop is not inluded again
        // we relax only during pop as we are sure, then edge(wt,node) will be included in MST 
        // no need for relax during pushing into PQ
        // nei node makes the overall scene better, push only if relaxing
        // *Note: Maintain vis, update after pop, dont update before pushing into PQ just check;
        while(!pq.empty()) { // in pq : relax only when pop, not when push
            auto it = pq.top(); pq.pop();
            int a = it[1], wa = it[0];
            if(vis[a]) continue;
            else vis[a] = true;
            dist[a] = wa; // update both dist(main) and ans
            ans += wa; // direct ans
            for(auto nei: adj[a]) {
                int b = nei[0], wb = nei[1];
                // check optimise cond during push, but update at pop only
                if(wb < dist[b]) {
                    pq.push({wb,b}); // pushing wb not dist[b] as wb smaller, and dist[b] not updated
                } 
            }
        }
        return accumulate(dist.begin(),dist.end(),0);
    }
};

// 7
// 7
// 0 1 3
// 1 3 3
// 1 5 10
// 2 4 6
// 2 6 9
// 3 6 8
// 4 5 6


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
