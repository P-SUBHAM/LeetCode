// Approach 1: logic
// robot 1 can take path :
// 0.......i     
//         i.......n-1
// Robot 2: either of this(max(top,bot))
//           i+1...n-1
// 0...i-1
// for each i calc max robot 2 can have, then robot-1 chooses min out of these
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long ans = LONG_LONG_MAX;
        vector<long long> top(n+1);
        vector<long long> bot(n+2);
        for(int i = 0; i < n; i++) {
            top[i+1] = grid[0][i] + top[i];
        }
        for(int i = 0; i < n; i++) {
            bot[i+1] = grid[1][i] + bot[i];
        }
        for(int i = 0; i < n; i++) {
            long long x = max(top[n-1+1]-top[i+1],bot[i-1+1]-bot[0]);
            ans = min(ans,x);
        }
        return ans;
    }
};