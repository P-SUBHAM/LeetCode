class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> dp;
        int n = stones.size();
        dp[0] = {0};
        for(auto it: stones) {dp[it];}
        for(int i = 0; i < n; i++) {
            int ind = i;
            int pos = stones[i];
            for(auto jumpl: dp[pos]) {
                for(int l = jumpl-1; l <= jumpl+1; l++) {
                    // if(l <= 0) continue;
                    int nextpos = pos + l;
                    if(dp.find(nextpos) != dp.end()) {
                        dp[nextpos].insert(l);
                    }
                }
            }
        }
        // for(auto it: dp) {
        //     cout<<it.first<<" : ";
        //     for(auto it2: it.second) {
        //         cout<<it2<<" ";
        //     }cout<<endl;
        // }
        return dp[stones[n-1]].size() > 0;
    }
};

// Approach 1: Memoization DP, (MLE:memory Limit Exceeded)
// dp[pos,k] = dp[pos+k-1,k-1] dp[pos+k,k] dp[pos+k+1,k+1]
class SolutionMemoDpOld19feb25 {
public:
    struct pairhash{
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    unordered_map<int,int> pos;
    unordered_map<pair<int,int>,bool,pairhash> memo;
    int rend;
    bool dpf(unordered_set<int>&stonest,int posv, int k) {
        if(posv==rend) return memo[{pos[posv],k}] = true;
        for(int i = -1; i <= 1; i++) {
            int npos = posv+(k+i); if(npos==posv) continue;
            if(stonest.find(npos)!=stonest.end()) {
                // cout<<npos<<" "<<npos-pos<<endl;
                if(dpf(stonest,npos,npos-posv)) {
                    return memo[{pos[posv],k}] = true;
                }
            }
        }
        return memo[{pos[posv],k}] = false;
    }
    bool canCross(vector<int>& stones) {
        unordered_set<int> stonest; memo.clear(); int n = stones.size();
        rend = stones.back(); pos.clear();
        for(int i = 0; i < n; i++) {
            stonest.insert(stones[i]); pos[stones[i]] = i;
        }
        if(stones.size()==1) return true;
        if(stones[1]!=1) return false; 
        return dpf(stonest,1,1);
    }
};
