// Approach 1: DSU
// if st and en belong to same component find value of & of all edge wt as we can traverse each wt as many times and the value of & can only decrease, which helps in minimising the wt travelled 
class Solution {
public:
    struct dsu { // nlogn + rank
        unordered_map<int,int> p;
        int find(int x) {
            if(p.find(x)==p.end()) return p[x] = x;
            return p[x] = (p[x] == x)?x: find(p[x]);
        }
        void join(int x, int y) {
            p[find(y)] = find(x);
        }
    };
    unordered_map<int,int> min_and;
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu G; // dsu
        vector<int> ans;

        for(auto e: edges) { // form dsu
            int u = e[0], v = e[1], wt = e[2];
            G.join(u,v);
        }
        for(auto e: edges) { // do and for same component edges
            int u = e[0], v = e[1], wt = e[2];
            int compno = G.find(u); // cout<<compno<<":"<<wt<<endl;
            if(min_and.find(compno) == min_and.end()) {
                min_and[compno] = wt;
            }
            else {
                min_and[compno] &= wt;
            }
        }
        
        for(auto q: query) { // find query value
            int st = q[0], en = q[1];
            if(G.find(st) != G.find(en)) { // belong to diff comp so no path
                ans.push_back(-1);
            }
            else { // if same comp, find min and val possible as we can visit all edges as we wish for
                ans.push_back(min_and[G.find(st)]);
            }
        }

        return ans;
    }
};