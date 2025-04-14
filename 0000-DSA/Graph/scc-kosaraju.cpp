//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
    void kosarajuSccDfs1(vector<vector<int>> &adj, int node, 
    vector<bool> &vis, stack<int> &st) {
        vis[node] = true;
        
        for(auto nei: adj[node]) {
            // node -> nei
            if(!vis[nei]) {
                kosarajuSccDfs1(adj,nei,vis,st);
            }
        }
        
        st.push(node);
    }
    void dfs3(vector<vector<int>> &adj, vector<bool> &vis, 
    int node, vector<int> &scc) {
        vis[node] = true;
        scc.push_back(node);
        
        for(auto nei: adj[node]) {
            if(vis[nei]) continue;
            dfs3(adj,vis,nei,scc);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        
        int n = adj.size();
        vector<vector<int>> scc_list;
        vector<bool> vis(n);
        stack<int> st;
        
        // 1. first dfs traversal for all unvis node
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            kosarajuSccDfs1(adj,i,vis,st);
        }
        
        // 2. reverse edges and reset vis
        vector<vector<int>> adjT(n);
        for(int i = 0; i < n; i++) {
            vis[i] = false;
            for(int nei: adj[i]) {
                int u = i, v = nei;
                // u --> v rev: v --> u
                adjT[v].push_back(u);
            }
        }
        
        // stack<int> temp; // debug
        // while(!st.empty()) {
        //     temp.push(st.top()); cout<<st.top()<<" "; st.pop(); 
        // }cout<<endl;
        // while(!temp.empty()) {
        //     st.push(temp.top()); temp.pop(); 
        // }
        
        // 3. dfs acc to stack nodes (acc to time ascending)
        while(!st.empty()) {
            int node = st.top(); st.pop();
            if(vis[node]) continue;
            vector<int> scc;
            dfs3(adjT,vis,node,scc);
            scc_list.push_back(scc);
        }
        // for(auto scc: scc_list) { // log
        //     for(auto it: scc) {
        //         cout<<it<<" ";
        //     } cout<<endl;
        // }
        return scc_list.size();
        
    }
};

// 5
// 4
// 1 2
// 2 3
// 0 4
// 0 2


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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends
