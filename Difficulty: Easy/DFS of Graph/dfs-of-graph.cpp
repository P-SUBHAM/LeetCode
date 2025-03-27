//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        int n = adj.size();
        vector<bool> vis(n);
        stack<int> st;
        st.push(0);
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            if(!vis[node]) {
                vis[node] = true;
                ans.push_back(node);
            } 
            for(int i = adj[node].size()-1; i >= 0; i--) {
                int nei = adj[node][i];
                if(!vis[nei]) {
                    st.push(nei);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends