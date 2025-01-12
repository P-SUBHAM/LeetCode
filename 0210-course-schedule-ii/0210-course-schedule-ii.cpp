// Approach 1: Topological Sort
// Push all nodes with 0 indegree into queue(bfs)
// keep poping element and decreasing indegree of neighbor node, if neihgbor node indeg = 0, push into queue
// keep count, if count not equal to all elements then topolocal sort doesnt exist
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        set<int> notpresent; set<int> present;
        vector<int> indeg(numCourses);
        for(int i = 0; i < numCourses; i++) {
            notpresent.insert(i);
        }
        for(int i = 0; i < prerequisites.size(); i++) {
            vector<int> curr = prerequisites[i];
            indeg[curr[0]] ++;
            adj[curr[1]].push_back(curr[0]);
            notpresent.erase(curr[0]); present.insert(curr[0]);
            notpresent.erase(curr[1]); present.insert(curr[1]);
        }
        queue<int> qu; vector<bool> vis(numCourses,false);
        for(auto it: present) { // only for nodes cosidered in topo sort
            if(indeg[it] == 0) {
                qu.push(it);
                vis[it] = true;
            }
        }
        int cnt = 0; // to check if all elements in topo sort to check if totpo sort exists
        vector<int> ans;
        while(!qu.empty()) {
            int x = qu.front();
            qu.pop(); cnt++;
            ans.push_back(x);
            for(auto nei: adj[x]) {
                indeg[nei]--;
                if(indeg[nei] == 0 && !vis[nei]) { // if nei becomes 0 indeg and not vis then insert into qu
                    qu.push(nei);
                    vis[nei] = true;
                }
            }
        }
        if(cnt != present.size()) {
            return {};
        }
        for(auto it: notpresent) {
            ans.push_back(it);
        }
        return ans;
    }
};