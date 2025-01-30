// Approach 1: Bipartite Graph + ConectedComponent + LevelOrderBFS
// 1. check if bipartite or not, if not return -1
// 2. Find a connected component, Find maxgrp len possible from this comp
// 3. Run Level order bfs from every node in comp list to find max lev for comp
class Solution {
public:
    vector<unordered_set<int>> adj;
    int n;
    vector<int> col;
    bool bipart;
    void dfscolour(int src, int colc) {
        col[src] = colc;
        colc^=1;
        for(auto nei: adj[src]) {
            if(col[nei]==-1) { // not vis ok - col it
                dfscolour(nei,colc);
            }
            else if(col[nei]!=colc) { // already col with othr col not bipart
                bipart = false;
            }
        }
    }
    bool isBipartite() {
        bipart = true; // assignment
        col.resize(n+1,-1); // -1:unvis 0:col0 1:col1
        for(int i = 1; i <= n; i++) {
            if(col[i]==-1) {
                dfscolour(i,0);
            }
        }
        return bipart;
    }
    // visites all node in comp, then ret max grp size(farthest bfs level)
    int maxcomp(int src, vector<int> &comp, int compno) {
        set<int> comppart;
        stack<int> st; st.push(src);comp[src] = compno;comppart.insert(src);
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            for(auto nei: adj[node]) {
                if(comp[nei]==-1) {//unvisited
                    st.push(nei); comp[nei] = compno; comppart.insert(nei);
                }
            }
        }
        int maxgrplen = 0;
        // cout<<"compparts: ";
        // need to find max bfs level from each comppart node
        for(auto node: comppart) {
            // cout<<" nd:"<<node<<" ";
            // Do level order bfs starting from each node in comp
            queue<int> qu; vector<int> vis(n+1,false); int lev = 0;
            qu.push(node); vis[node] = true;
            while(!qu.empty()) {
                int sz = qu.size();
                lev++;
                for(int i = 0; i < sz; i++) {
                    auto nd = qu.front(); qu.pop();
                    for(auto nei: adj[nd]) {
                        if(vis[nei]==false) {//unvis
                            vis[nei]=true; qu.push(nei);
                        }
                    }
                }
            }
            maxgrplen = max(maxgrplen,lev);
            //cout<<"lev:"<<lev<<endl;
        }//cout<<endl;
        return maxgrplen;
    }
    int magnificentSets(int N, vector<vector<int>>& edges) {
        n = N; adj.clear(); adj.resize(n+1);
        for(auto e: edges) {int u = e[0], v = e[1]; adj[u].insert(v);adj[v].insert(u);}
        if(!isBipartite()) return -1; // not bipartite so cant be into groups
        // find a comp and do its level order bfs to find max grp for the comp
        vector<int> comp(n+1,-1); int maxgrp = 0, compno = 0;
        for(int i = 1; i <= n; i++) {
            if(comp[i]==-1) {
                int x = maxcomp(i,comp,++compno);
                maxgrp += x;
                // cout<<"node:"<<i<<"maxlen:"<<x<<endl;
            }
        }
        return maxgrp;
    }
};