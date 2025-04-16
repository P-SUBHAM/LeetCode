class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
    int src, int dst, int k) {
        int inf = 1e9;
        vector<int> dist(n,inf); dist[src] = 0;
        vector<int> tempdist;
        for(int t = 0; t < k+1; t++) {
            tempdist = dist;
            // for(auto it: tempdist) cout<<it<<" "; cout<<endl;
            for(auto edge: flights) {
                int u = edge[0], v = edge[1], w = edge[2];
                if(dist[u] == inf) continue;
                tempdist[v] = min(tempdist[v],dist[u]+w);
            }
            
            dist = tempdist;
        }
        // for(auto it: tempdist) cout<<it<<" "; cout<<endl;
        return (dist[dst]==inf)?-1:dist[dst];
    }
};

// Do bfs traversal relaxing dist
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int inf = 1e9;
        vector<vector<vector<int>>> adj(n); // {nei,wt}
        for(auto edge: flights) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
        }
        queue<vector<int>> qu;
        vector<int> dist(n,inf); dist[src] = 0;
        qu.push({0,0,src}); // stops taken,dist to node, node
        while(!qu.empty()) {
            auto qunode = qu.front(); qu.pop();
            int stops = qunode[0], d = qunode[1], node = qunode[2];
            if(stops > k) continue; // k intermediate stops
            for(auto nei: adj[node]) {
                // node - nei
                int u = node, v = nei[0], wt = nei[1];
                if(d + wt < dist[v] && stops <= k) { // here dist or d will works as actually d is what is needed below but dist cause over repeat and hence tle
                    dist[v] = d + wt; // check d vs dist[u]; // imp to use d here
                    qu.push({stops+1,dist[v],v});
                }
            }
        }
        return (dist[dst] == inf)?-1:dist[dst];
    }
};

// tried bellman ford TODO
class Solutionb {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9); dist[src] = 0;
        for(int i = 0; i < k + 1; i++) {
            for(auto edges: flights) {
                int u = edges[0], v = edges[1], wt = edges[2];
                if(dist[u] == 1e9) continue;
                dist[v] = min(dist[v],dist[u]+wt);
            }
        }
        return (dist[dst]==1e9)? -1: dist[dst];
    }
};