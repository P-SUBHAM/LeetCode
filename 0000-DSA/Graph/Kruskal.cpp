class Solution {
  public:
    // kruskal
    struct dsu{
        unordered_map<int,int> p;
        int find(int x) {
            if(p.find(x)==p.end()) return p[x] = x;
            return p[x] = (p[x] == x? x: find(p[x]));
        }
        void join(int x, int y) {
            p[find(x)] = find(y);
        }
    };
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        dsu D1; int inf = 1e9;
        vector<int> dist(V,inf);
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(int i = 0; i < V; i++) {
            for(auto row: adj[i]) {
                int u = i, v = row[0], w = row[1];
                pq.push({w,u,v});
            }
        }
        int ans = 0;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int u = it[1], v = it[2], w = it[0];
            if(D1.find(u)!=D1.find(v)) {
                ans += w;
                D1.join(u,v);
            }
        }
        return ans;
    }
};
