// DP 1 array : optimisation tabular
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<int> dp(n2+1);
        dp[n2] = 1;
        for(int j = n2-1; j >= 0; j--) {
            if(p[j] == '*') {
                dp[j] = dp[j+1];
            }
            else {
                dp[j] = false;
            }
        }
        for(int i = n1-1; i>= 0; i--) {
            int nextj1 = dp[n2];
            dp[n2] = false;
            for(int j = n2-1; j >= 0; j--) {
                int temp = dp[j]; //nextj
                if(s[i] == p[j] or p[j] == '?') {
                    dp[j] = nextj1;
                }
                else if(p[j] == '*') {
                    dp[j] = dp[j+1] || dp[j];
                }
                else {
                    dp[j] = false;
                }
                nextj1 = temp;
            }
        }
        return dp[0];
    }
};

class Solution21 {
public:
// if si==pj||pj=='?' dpij = dpi+1j+1 // 
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<int>> dp;
        vector<int> next(n2+1);
        vector<int> curr(n2+1);
        next[n2] = 1;
        for(int j = n2-1; j >= 0; j--) {
            if(p[j] == '*') {
                next[j] = next[j+1];
            }
            else {
                next[j] = false;
            }
        }
        for(int i = n1-1; i>= 0; i--) {
            curr[n2] = false;
            for(int j = n2-1; j >= 0; j--) {
                if(s[i] == p[j] or p[j] == '?') {
                    curr[j] = next[j+1];
                }
                else if(p[j] == '*') {
                    curr[j] = curr[j+1]||next[j];
                }
                else {
                    curr[j] = false;
                }
            }
            next = curr;
        }
        return next[0];
    }
};

// Approach 1: Memoization
// if match i=j or j=? i+1,j+1
// if j=* (i+1,j+1||i,j+1(skipj))||(i+1,j)
class Solution1 {
public:
    vector<vector<int>> dp;
    bool dpf(string &s, string &p, int i, int j) {
        int n1 = s.size(), n2 = p.size();
        if(i == n1 and j == n2) {
            return true;
        } 
        if(i > n1) {return false;} // make sure i Not OutOfBound
        if(j == n2) { // i == n1 fine as pattern may still continue
            return false;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == p[j] or p[j] == '?') {
            return dp[i][j] = dpf(s,p,i+1,j+1);
        }
        if(p[j] == '*') {
            return dp[i][j] = dpf(s,p,i,j+1)||dpf(s,p,i+1,j);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        dp.clear();
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return dpf(s,p,0,0);
    }
};
// "acdcb" "a*c?b"
