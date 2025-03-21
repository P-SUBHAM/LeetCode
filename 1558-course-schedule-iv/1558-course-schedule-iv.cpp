// Assume input has no cycle
class Solution {
public:
    map<int,set<int>> pre;
    int cycle;
    void CreatePrerequisite(int n, vector<vector<int>> prereq) {
        // find topo sort, pass earlier pre-req to child & check
        cycle = false; int cnt = 0;
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto it: prereq) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            if(indeg[i]==0) {
                qu.push(i);
            }
        }
        while(!qu.empty()) {
            int x = qu.front(); qu.pop();
            for(auto nei: adj[x]) {
                if(--indeg[nei] == 0) {
                    qu.push(nei);
                }
                // propagate to child everytime
                pre[nei].insert(pre[x].begin(),pre[x].end());
                pre[nei].insert(x);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int q = queries.size(); pre.clear();
        CreatePrerequisite(numCourses,prerequisites);
        vector<bool> ans; int n = numCourses;
        function<vector<bool>()> query = [&]() ->vector<bool> {
            vector<bool> ansf;
            for(auto it: queries) {
                int prereq = it[0], course = it[1];
                if(pre[course].find(prereq)!=pre[course].end()) {
                    ansf.push_back(true);
                }
                else {
                    ansf.push_back(false);
                }
            }
            return ansf;
        };
        ans = query();
        return ans;
    }
};