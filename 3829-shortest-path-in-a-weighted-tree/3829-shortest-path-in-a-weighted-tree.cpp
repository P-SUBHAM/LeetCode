class Solution {
public:
    static const int NMAX = 100005;
    int tin[NMAX], tout[NMAX], timer = 1;
    long long initialDist[NMAX];
    int parent[NMAX]; 
    int parEdgeWeight[NMAX]; 
    vector<vector<vector<int>>> adj;
    
    struct BIT {
        int n;
        vector<long long> fenw;
        BIT(int n): n(n) { fenw.assign(n + 1, 0); }
        void update(int i, long long delta) {
            for(; i <= n; i += i & -i)
                fenw[i] += delta;
        }
        long long query(int i) {
            long long sum = 0;
            for(; i > 0; i -= i & -i)
                sum += fenw[i];
            return sum;
        }
        void range_update(int l, int r, long long delta) {
            update(l, delta);
            update(r + 1, -delta);
        }
    };
    
    void dfs(int node, int par, long long dist) {
        parent[node] = par;
        initialDist[node] = dist;
        tin[node] = timer++;
        for (auto &edge : adj[node]) {
            int nxt = edge[0], w = edge[1];
            if (nxt == par)
                continue;
            parEdgeWeight[nxt] = w;
            dfs(nxt, node, dist + w);
        }
        tout[node] = timer - 1;
    }
    
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj.clear();
        adj.resize(n + 1);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        dfs(1, 0, 0);
        BIT bit(n + 2);
        vector<int> ans;
        for (auto query : queries) {
            if (query[0] == 2) {
                int node = query[1];
                long long init_d = initialDist[node];
                long long additional = bit.query(tin[node]);
                long long tot = init_d + additional;
                ans.push_back(tot);
            }
            else { 
                int u = query[1], v = query[2], w = query[3];
                int child = v;
                if (parent[u] == v)
                    child = u;
                int diff = w - parEdgeWeight[child];
                parEdgeWeight[child] = w;
                bit.range_update(tin[child], tout[child], diff);
            }
        }
        return ans;
    }
};