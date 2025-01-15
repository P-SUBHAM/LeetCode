//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    // Approach 1:
    // iter n-1 times on all edges e (n-1 as max path n-1 edges)
    // u v w min(dist[v],dist[u]+w)
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int inf = 1e8;
        vector<int> dist(V,inf); dist[src] = 0;
        bool change;
        for(int i = 0; i < V; i++) {
            change = false;
            for(auto e: edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u] != inf) { // update only if helping inf+delta~inf
                    if(dist[v] > dist[u]+w) {
                        change = true;
                    }
                    dist[v] = min(dist[v],dist[u]+w);
                }
            }
        }
        return (change == false) ? dist : vector<int>(1,-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends