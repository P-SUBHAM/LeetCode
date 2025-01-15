//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<bool> vis;
    vector<int> dist;
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int v = adj.size();
        vis.clear(); vis.resize(v,false);
        dist.clear(); dist.resize(v,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        pq.push({0,src}); dist[src] = 0; // no vis need as a->b->a wont happen as wt will increase
        while(!pq.empty()) {
            pair<int,int> pe = pq.top(); pq.pop();
            int wt = pe.first; int curr = pe.second;
            for(auto it: adj[curr]) {
                if(dist[it.first] > dist[curr] + it.second) { // (nei,curr+neiWT)
                    dist[it.first] = dist[curr] + it.second;
                    pq.push({it.second,it.first});
                }
            }
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
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends