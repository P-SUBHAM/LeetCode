// Approach 1.1 : memoization with vector (static declaration)
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(1e4 + 1, -1);
        if(n==0) return 0;
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans = 1e9;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans,1 + numSquares(n-i*i));
        }
        return dp[n] = ans;
    }
};

// // Approach 1: memoization with map
// class Solution {
// public:
//     unordered_map<int,int> dp;
//     int numSquares(int n) {
//         if(n==0) return 0;
//         if(dp.find(n) != dp.end()) {
//             return dp[n];
//         }
//         int ans = 1e9;
//         for(int i = 1; i*i <= n; i++) {
//             ans = min(ans,1 + numSquares(n-i*i));
//         }
//         return dp[n] = ans;
//     }
// };