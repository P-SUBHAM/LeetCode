#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1e18
const int mod = 1e9+7;

// dijkstra
void solve() 
{
    int n,e; cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n+1);
    while(e--) {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dist(n+1,inf); dist[1] = 0;
    vector<int> vis(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()) {
        auto v = pq.top(); pq.pop();
        int node = v.second, dis = v.first;
        if(dis != dist[node]) {continue;} // VIMP
        for(auto nei: adj[node]) {
            if(dis + nei.second < dist[nei.first]) {
                dist[nei.first] = dis + nei.second;
                pq.push({dist[nei.first],nei.first});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout<<dist[i]<<" ";
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; // cin>>t;
    while(t--) solve();
    return 0;
}
