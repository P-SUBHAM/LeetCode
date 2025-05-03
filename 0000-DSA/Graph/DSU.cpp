// DSU with union by size, get set size, if set exists
struct DSU { // union by size
    unordered_map<ll, ll> p; // Parent map
    unordered_map<ll, ll> s; // size map
    ll find_set(ll x) {
        if (p.find(x) == p.end()) {s[x]=1; return p[x] = x;} // Lazy initialization
        return (p[x] == x) ? x : p[x] = find_set(p[x]); // Path compression
    }
    void union_set(ll x, ll y) {
        x = find_set(x), y = find_set(y);
        if(x == y) return;
        if(s[x] < s[y]) swap(x,y);
        p[y] = x; s[x] += s[y];
    }
    bool exist_set(ll x) {
        return (p.find(x) != p.end());
    }
    ll find_size(ll x) {
        return s[find_set(x)];
    }
};

// Simplest DSU implementation O(nlogn)
struct DSU {
    unordered_map<int,int> p;
    int find(int x) {
        if(p.find(x)==p.end()) return p[x] = x;
        return (p[x] == x) ? x : p[x] = find(p[x]);
    }
    void join(int x, int y) {
        p[find(x)]=find(y);
    }
};
// annecdote: map: TLE unordered_map:906ms 

// DSU with path Compression and Union by rank
struct DSU {
    unordered_map<int, int> p; // Parent map
    unordered_map<int, int> rank; // Rank map (optional, for union by rank)
    int find(int x) {
        if (p.find(x) == p.end()) return p[x] = x; // Lazy initialization
        return (p[x] == x) ? x : p[x] = find(p[x]); // Path compression
    }
    void join(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr != yr) {
            if (rank[xr] < rank[yr]) { p[xr] = yr;} 
            else if (rank[xr] > rank[yr]) {p[yr] = xr;} 
            else {p[yr] = xr;rank[xr]++;}
        }
    }
};
// annecdote: map: 1999ms unordered_map: 890ms
