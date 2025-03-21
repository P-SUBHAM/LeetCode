// Approach 1: Topological Sort
// Go level wise, propage its time to child, child updates and keep max pre-requisite time
// return maxtime incl of all courses time
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans = 0;
        queue<int> qu; // {node,pre-req time}
        vector<int> indeg(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto e: relations) {
            int u = e[0], v = e[1]; indeg[v]++;
            adj[u].push_back(v);
        }
        vector<int> comptime(n+1);
        for(int i = 1; i <= n; i++) {
            if(indeg[i]==0) {
                qu.push({i}); comptime[i] = time[i-1];
            }
        }
        // cout<<"time:";for(auto it: time) cout<<" "<<it; cout<<endl;
        // cout<<"comptime: ";for(auto it: comptime) cout<<" "<<it; cout<<endl;
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            // cout<<"node:"<<node;
            for(auto nei: adj[node]) {
                // cout<<"nei:"<<nei;
                comptime[nei] = max(comptime[nei],time[nei-1]+comptime[node]);
                // cout<<"t:"<<comptime[nei];
                if(--indeg[nei]==0) {
                    qu.push(nei);
                }
            }//cout<<endl;
        }
        // cout<<"comptime: ";for(auto it: comptime) cout<<" "<<it; cout<<endl;
        return *max_element(comptime.begin(),comptime.end());
    }
};