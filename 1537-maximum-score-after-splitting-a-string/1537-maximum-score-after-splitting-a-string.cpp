class Solution {
public:
    int maxScore(string s) {
        int totones = 0, zeros = 0, ones = 0, ans = 0, n = s.size();
        for(auto x: s) {if(x == '1') totones++;}
        for(int i = 0; i < n-1; i++) {
            char x = s[i];
            if(x == '0') {zeros++;}
            if(x == '1') {ones++;}
            ans = max(ans,zeros+(totones-ones));
        }
        return ans;
    }
};