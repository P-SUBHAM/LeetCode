// DSU with path Compression and Union by rank
struct dsu {
    map<int, int> p; // Parent map
    map<int, int> rank; // Rank map (optional, for union by rank)
    int find(int x) {
        if (p.find(x) == p.end()) return p[x] = x; // Lazy initialization
        return (p[x] == x) ? x : p[x] = find(p[x]); // Path compression
    }
    void make(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr != yr) {
            if (rank[xr] < rank[yr]) { p[xr] = yr;} 
            else if (rank[xr] > rank[yr]) {p[yr] = xr;} 
            else {p[yr] = xr;rank[xr]++;}
        }
    }
};