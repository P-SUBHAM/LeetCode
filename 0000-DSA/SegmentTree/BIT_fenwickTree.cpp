// fenwick tree short
struct BIT {
    vector<long long> fenw; int n;
    BIT(int n_):n(n_) {fenw.resize(n+1,0);} // 0,1-n
    long long query(int i) {
        long long sum = 0;
        for(; i > 0; i -= i&-i)
            sum += fenw[i];
        return sum; 
    }
    void update(int i, int d) {
        for(; i <= n; i += i&-i)
            fenw[i] += d;
    }
};

// fenwick tree
struct BIT {
    vector<long long> fenw; int n;
    BIT(int n_):n(n_) {fenw.resize(n+1,0);} // 0,1-n
    long long query(int i) {
        long long sum = 0;
        for(; i > 0; i -= i&-i)
            sum += fenw[i];
        return sum; 
    }
    void update(int i, int d) {
        for(; i <= n; i += i&-i)
            fenw[i] += d;
    }
    long long rangeUpdate(long long l, long long r, long long d) {
        update(l,d); update(r+1,d);
    }
    long long rangeQuery(int l, int r) {
        return query(r) - query(l-1);
    }
    long long pointQuery(int l) {
        return query(l) - query(l-1);
    }
};
