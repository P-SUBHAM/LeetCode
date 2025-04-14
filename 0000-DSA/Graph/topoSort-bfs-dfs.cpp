#include <bits/stdc++.h>
using namespace std;

class TopoSortBFS {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};

// post-order traversal + reverse final traversal path
class TopoSortDFS {
public:
    vector<int> ans;

    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
        ans.push_back(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        ans.clear();
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    int V = 6;
    vector<int> adj[V];
    
    // sample DAG
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(5);
    // Topological Sort (BFS / Kahn's): 0 1 2 3 4 5 
    // Topological Sort (DFS): 0 1 3 2 4 5 

    // // Sample cyclic DG
    // adj[0].push_back(1);
    // adj[1].push_back(2);
    // adj[3].push_back(1);
    // adj[2].push_back(4);
    // adj[4].push_back(3);
    // adj[4].push_back(5);
    // // Topological Sort (BFS / Kahn's): 0 
    // // Topological Sort (DFS): 0 1 2 4 5 3 

    cout << "Graph Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }

    TopoSortBFS bfsSolver;
    TopoSortDFS dfsSolver;

    vector<int> bfsResult = bfsSolver.topoSort(V, adj);
    vector<int> dfsResult = dfsSolver.topoSort(V, adj);

    cout << "\nTopological Sort (BFS / Kahn's): ";
    printVector(bfsResult);

    cout << "Topological Sort (DFS): ";
    printVector(dfsResult);

    return 0;
}
