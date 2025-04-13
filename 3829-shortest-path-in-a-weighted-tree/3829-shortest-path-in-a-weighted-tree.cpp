class Solution {
public:
    int timer = 1;
    vector<int> tin;
    vector<int> tout;
    vector<vector<vector<int>>> adj;
    vector<int> edgeWt;
    vector<int> parent;
    void dfs(int node, int par) {
        tin[node] = timer++;
        parent[node] = par;
        for(auto nei: adj[node]) {
            int v = nei[0], w = nei[1];
            if(v == par) continue;
            edgeWt[v] = w;
            dfs(v,node);
        }
        tout[node] = timer++;
    }
    struct BIT {
        vector<long long> fenw; int n;
        BIT(int n_):n(n_) {fenw.resize(n_+2,0);}//0,1-n,n+1
        long long query(int i) {
            long long sum = 0;
            for(;i>0; i-=i&-i) 
                sum += fenw[i];
            return sum;
        }
        void update(int i, int diff) {
            for(; i <= n; i += i&-i)
                fenw[i] += diff;
        }
    };
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        tin.resize(n+1);
        tout.resize(n+1);
        adj.resize(n+1);
        edgeWt.resize(n+1);
        parent.resize(n+1);
        vector<int> ans;
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,0);
        BIT ftree(2*n); // for tin,tout
        for(int i = 1; i <= n; i++) {
            ftree.update(tin[i],edgeWt[i]);
            ftree.update(tout[i],-1*edgeWt[i]);
        }
        for(auto query: queries) {
            if(query[0] == 2) {
                int dest = query[1];
                // cout<<dest<<" ";
                // cout<<ftree.query(tin[dest])<<endl;
                ans.push_back(ftree.query(tin[dest]));
            }
            else {
                int u = query[1], v = query[2], w = query[3];
                int child = v;
                if(parent[u] == v) child = u;
                int oldw = edgeWt[child]; // any method is fine, only update ftree or edge wt arr too
                oldw = ftree.query(tin[child]) - ftree.query(tin[child]-1);
                ftree.update(tin[v],w-oldw);
                ftree.update(tout[v],-w-(-oldw));
                edgeWt[child] = w;
            }
        }
        return ans;
    }
};

/*n="4" edges = "[[1,2,2],[2,3,3],[3,4,4]]" query="[[2,4],[1,2,3,10],[2,3],[1,2,3,1],[2,3]]" ans="[9,12,3]"*/