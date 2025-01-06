// Approach 1 BackTracking
// global ans, curr valid str, whenever valid add to global ans
class Solution {
public:
    void paranthesisBT(vector<string> &ans, string curr, int o, int c, int n) {
        if(o == n && c == n) {ans.push_back(curr); return;} // base
        if(o < n) {paranthesisBT(ans,curr+'(',o+1,c,n);} // "(" if o < n
        if(c < o) {paranthesisBT(ans,curr+')',o,c+1,n);} // ")" if c < o
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paranthesisBT(ans,"",0,0,n);
        return ans;
    }
};