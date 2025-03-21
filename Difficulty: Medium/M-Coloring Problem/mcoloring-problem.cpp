//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// backtracking
class Solution {
  public:
    bool safe(vector<vector<int>>&adj, int c, int node, vector<int> &col) {
        for(auto nei: adj[node]) {
            if(col[nei] == c) return false;
        }
        return true;
    }
    bool rec(int v, vector<vector<int>> &adj, int m, int i, vector<int> &col) {
        if(i == v) return true;
        for(int c = 0; c < m; c++) {
            if(safe(adj,c,i,col)) {
                col[i] = c;
                if(rec(v,adj,m,i+1,col)) {
                    return true;
                }
                col[i] = -1;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<int> col(v,-1);
        vector<vector<int>> adj(v);
        for(auto e: edges) {
            int u = e.first, v = e.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return rec(v,adj,m,0,col);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends