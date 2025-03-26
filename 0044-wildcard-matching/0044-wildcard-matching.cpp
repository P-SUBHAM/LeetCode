// Approach 1: Memoization
// if match i=j or j=? i+1,j+1
// if j=* (i+1,j+1||i,j+1(skipj))||(i+1,j)
class Solution {
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