// Approach 1: DSU
// keep adding edges as long as they dont form cycle, once cycle cond is true ret edge
class dsu {
    public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
    int find_set(int x) {
        if(parent.find(x)==parent.end()) return parent[x] = x;//makep
        if(parent[x]==x) return x;//found parent
        return parent[x] = find_set(parent[x]);//find parent's parent
    }
    void union_set(int x, int y) {
        int px = find_set(x), py = find_set(y);
        if(px==py) return;
        if(rank[px]!=rank[py]) {
            if(rank[px]<rank[py]) swap(px,py); // make x larger rank
            parent[py]=px;
        }
        else {
            parent[py]=px; rank[px]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu Graph;
        for(auto e: edges) {
            int u = e[0], v = e[1];
            int up = Graph.find_set(u), vp = Graph.find_set(v);
            if(up==vp) return e; // cycle detected due to u-v
            Graph.union_set(u,v);
        }
        return {};
    }
};