// Approach 1
// ) <= ( at every index, if ) > (, then balance adding (
// match all left out ( brackets
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, open = 0, close = 0;
        for(auto c: s) {
            if(c == '(') {
                open++;
            }
            else {
                close++;
            }
            if(close > open) {
                ans++;
                open++;
            }
        }
        ans += abs(open-close); // balance left out open (
        return ans;
    }
};