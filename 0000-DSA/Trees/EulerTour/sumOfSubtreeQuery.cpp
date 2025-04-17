// Euler Tour to find sum of subtree query using fenwick tree
#include<bits/stdc++.h>
using namespace std;

int timer = 0;
struct BIT {
    vector<long long> fenw; int n;
    BIT(int n_):n(n_) {fenw.resize(n+3,0);} // 0,1-n
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

void dfs(vector<vector<int>> &adj, int src, vector<int> &tin, vector<int> &tout) {
    tin[src] = ++timer;
    for(auto nei: adj[src]) {
        if(tin[nei]!=-1) continue;
        dfs(adj,nei,tin, tout);
    }
    tout[src] = timer; // use timer-1 if u use post incremenet timer++
}

int main()
{
    int n,q; cin>>n>>q;
    BIT ftree(n);
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> tin(n+1,-1);
    vector<int> tout(n+1,-1);
    dfs(adj,1,tin,tout);
    for(int i = 1; i <= n; i++) {
        int time = tin[i];
        int val = v[i-1];
        ftree.update(time,val);
    }
    // for(int i = 1; i <= n; i++) {
    //     cout<<ftree.query(i)-ftree.query(i-1)<<" ";
    // }cout<<endl;
    // for(int i = 1; i <= n; i++) {
    //     cout<<tin[i]<<" ";
    // }cout<<endl;
    // for(int i = 1; i <= n; i++) {
    //     cout<<tout[i]<<" ";
    // }cout<<endl;
    for(int i = 0; i < q; i++) {
        int type; cin>>type;
        if(type == 2) {
            int node; cin>>node;
            int sttime = tin[node], entime = tout[node];
            long long ans = ftree.query(entime) - ftree.query(sttime-1);
            cout<<ans<<endl;
        }
        else { 
            int node,val; cin>>node>>val;
            int ogNodeVal = ftree.query(tin[node]) - ftree.query(tin[node]-1);
            ftree.update(tin[node],val-ogNodeVal);
        }
    }
    return 0;
}