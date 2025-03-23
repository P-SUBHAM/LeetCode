class Solution {
public:
    vector<vector<vector<long long>>> getAdjWtFromEdges(int n, vector<vector<int>>& edges) {
        vector<vector<vector<long long>>> adj(n); // [node]: {nei,wt}
        for(auto e: edges) {
            int u = e[0], v = e[1], wt = e[2]; // u -(w)- v
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // cout<<"log AdjWt"<<endl; for(auto row: adj) { for(auto nei: row) {cout<<nei[0]<<"."<<nei[1]<<" ";}cout<<endl;}
        return adj;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<long long>>> adjWt = getAdjWtFromEdges(n,roads);
        long long inf = 1e12;
        vector<long long> dist(n,inf); dist[0] = 0;
        vector<long long> ways(n,0); ways[0] = 1;
        priority_queue<vector<long long>,vector<vector<long long>>,greater<>> pq;
        pq.push({0,0});

        while(!pq.empty()) {
            auto pqe = pq.top(); pq.pop();
            int u = pqe[1]; long long we1 = pqe[0];
            for(auto nei: adjWt[u]) {
                int v = nei[0], wt = nei[1];
                // VVIMP
                if(we1+wt < dist[v]) { // use edge weight from pq and not global dist, to avoid over counting, dijsktra op will be fine but no of ways will be over counted
                    dist[v] = dist[u]+wt;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                    // cout<<u<<v<<"-"<<wt<<we1<<endl;
                    // cout<<"d1:";for(auto d: dist) cout<<d<<" "; cout<<endl;
                    // cout<<"w:";for(auto w: ways) cout<<w<<" "; cout<<endl; 
                }
                else if(we1+wt == dist[v]) {
                    long long modulo = 1e9+7;
                    ways[v] += ways[u];
                    ways[v] %= modulo;
                    // cout<<u<<v<<"-"<<wt<<we1<<endl;
                    // cout<<"d2:";for(auto d: dist) cout<<d<<" "; cout<<endl;
                    // cout<<"w:";for(auto w: ways) cout<<w<<" "; cout<<endl; 
                }
            }
        }
        // for(auto d: dist) cout<<d<<" "; cout<<endl;
        // for(auto w: ways) cout<<w<<" "; cout<<endl;
        return ways[n-1];
    }
};


// TO-DO
// get edges where dist[u] + weight = dist[v], here dist[x] = dist[0-x]
// no of ways to reach dest from src in a dag - todo
class SolutionTodo1 {
public:
    vector<vector<vector<int>>> getAdjWtFromEdges(int n, vector<vector<int>>& edges) {
        // [node]: {nei,wt}
        vector<vector<vector<int>>> adj(n);
        for(auto e: edges) {
            int u = e[0], v = e[1], wt = e[2]; // u -(w)- v
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // cout<<"log AdjWt"<<endl;
        // for(auto row: adj) { // log
        //     for(auto nei: row) {
        //         cout<<nei[0]<<"."<<nei[1]<<" ";
        //     }cout<<endl;
        // }
        return adj;
    }
    vector<vector<int>> FloydWarshallMultiSrc(int n, vector<vector<vector<int>>> &adjWt) {
        int inf = 1e9;
        vector<vector<int>> dist(n,vector<int>(n,inf));
        for(int i = 0; i < n; i++) {
            for(auto nei: adjWt[i]) {
                int u = i, v = nei[0], w = nei[1];
                dist[u][v] = w;
                dist[v][u] = w;
            }
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    int u = i, v = j;
                    // u - k - v
                    if(dist[u][k] < inf && dist[k][v] < inf) {
                        dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v]);
                    }
                }
            }
        }
        // cout<<"log: Dist matrix\n";
        // for(auto row: dist) { // log dist matrix
        //     for(auto x: row) cout<<x<<" "; cout<<endl;
        // }
        return dist;
    }
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        int n = adj.size();vector<int> dist(n,1e9);dist[src] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            for(auto nei: adj[node[1]]) {
                int u = node[1], v = nei[0], wt = nei[1];
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt; pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
    int CountNoOfWaysWithDist(int src, int dest,vector<vector<vector<int>>> &adjWt, int dist,map<vector<int>,int> &dp,unordered_map<int,bool> &vis) {
        if(dp.find({src,dist})!=dp.end()) return dp[{src,dist}];
        if(dist < 0) {
            return dp[{src,dist}] = 0;
        }
        if(src == dest) {
            return dp[{src,dist}] = (dist == 0);
        }
        int cntWays = 0;
        for(auto nei: adjWt[src]) {
            int neinode = nei[0], wt = nei[1];
            if(vis[neinode]) continue;
            vis[neinode] = true;
            cntWays += CountNoOfWaysWithDist(neinode,dest,adjWt,dist-wt,dp,vis);
        }
        return dp[{src,dist}] = cntWays;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adjWt;
        adjWt = getAdjWtFromEdges(n,roads);

        // vector<vector<int>> MultiSrcShortestDist;
        // MultiSrcShortestDist = FloydWarshallMultiSrc(n,adjWt);

        vector<int> SingleSrcShortestDist;
        SingleSrcShortestDist = dijkstra(adjWt,0); // step 1


        vector<vector<int>> dag;
        for(auto e: roads) {
            int u = e[0], v = e[1], w = e[2];
            if(SingleSrcShortestDist[u]+w == SingleSrcShortestDist[v]) {
                dag.push_back(e); // step 1.2
            }
        }

        int min_src_dest = 0;
        // min_src_dest = MultiSrcShortestDist[0][n-1];
        min_src_dest = SingleSrcShortestDist[n-1];
        // cout<<min_src_dest<<endl;

        int ans = 0;
        map<vector<int>,int> dp;
        unordered_map<int,bool> vis; vis[0] = true;
        ans = CountNoOfWaysWithDist(0,n-1,adjWt,min_src_dest,dp,vis);
        // cout<<ans<<endl;
        return ans;
    }
};