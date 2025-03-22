class Solution {
public:
    vector<vector<int>> getAdjFromEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e: edges) {
            int u = e[0], v = e[1]; // u -- v
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    vector<int> dfsItr(int n, vector<vector<int>> &adj, int node,vector<bool> &vis) {
        stack<int> st;
        st.push(node);
        vector<int> dfsList;
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            if(!vis[node]) {
                vis[node] = true;
                dfsList.push_back(node);
            }
            for(auto nei: adj[node]) {
                if(!vis[nei]) {
                    st.push(nei);
                }
            }
        }
        return dfsList;
    }
    vector<vector<int>> getConnectedComponentList(int n, vector<vector<int>> &adj) {
        vector<vector<int>> connectedComponentList;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> dfsList;
                dfsList = dfsItr(n,adj,i,vis);
                connectedComponentList.push_back(dfsList);
            }
        }
        return connectedComponentList;
    }
    vector<vector<bool>> getAdjMFromList(int n,vector<vector<int>> &adj) {
        vector<vector<bool>> adjM(n,vector<bool>(n,0));
        for(int i = 0; i < n; i++) {
            for(auto nei: adj[i]) {
                int u = i, v = nei;
                adjM[u][v] = true;
            }
        }
        return adjM;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj;
        adj = getAdjFromEdges(n,edges);
        vector<vector<int>> connectedComponentList;
        connectedComponentList = getConnectedComponentList(n,adj);
        vector<vector<bool>> adjM = getAdjMFromList(n,adj);

        int completeComponentCount = 0;
        for(auto connectedComponent: connectedComponentList) {
            // for(auto it:connectedComponent) cout<<it<<" ";cout<<endl;//log
            int compLen = connectedComponent.size();
            bool completeComponent = true;
            for(int i = 0; i < compLen; i++) {
                for(int j = i + 1; j < compLen; j++) {
                    int u = connectedComponent[i],
                    v = connectedComponent[j];
                    // cout<<i<<":"<<j<<" "; // log
                    // check edge b/w i j
                    if(adjM[u][v] == false) {
                        completeComponent = false; break;
                    }
                } // cout<<endl;
                if(!completeComponent) {
                    break;
                }
            }
            if(completeComponent) {
                completeComponentCount++;
            }
        }

        return completeComponentCount;
    }
};