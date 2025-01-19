// Approach 1: Used modified PRIMS algo to find MST for directed Graph
class Solution {
public:
    vector<vector<int>> newedges;
    vector<vector<vector<int>>> nadj;
    vector<int> dist;
    int inf = 1e9;
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold){
        newedges = edges;
        nadj.clear(); nadj.resize(n);
        dist.clear(); dist.resize(n,inf);
        for(auto &x: newedges) { // x:A->B,W
            swap(x[0],x[1]);
            nadj[x[0]].push_back({x[1],x[2]}); // B,W
        }
        vector<int> vis(n,false);
        int ans = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0}); dist[0] = 0;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int a = it[1], wa = it[0]; 
            if(vis[a]) continue;
            else vis[a] = true; 
            dist[a] = wa; // update both dist[a] and local ans
            ans = max(ans,wa); // max wt in MST edge
            // cout<<"v:"<<a<<" wt:"<<wa<<endl;
            for(auto nei: nadj[a]) {
                int b = nei[0], wb = nei[1];
                if(dist[b] > wb && !vis[b]) {
                    pq.push({wb,b});
                }
            }
        }
        for(auto d: dist) {
            if(d == inf) {
                return -1;
            }
        }
        return ans;
    }
};