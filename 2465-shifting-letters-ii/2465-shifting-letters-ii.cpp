// Approach 1: Using relative array to maintain diff btw neighbours
// [l,r,diff] -> v[l] += diff; v[r+1] -= diff
// s[i] = (s[i] - 'a' + (diff(+/-))  + 26)%26; will keep in range
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n);
        for(int i = 1; i < n; i++) {v[i] = s[i] - s[i-1]; v[i] = (v[i]+26)%26;}
        for(auto it: shifts) {
            int l = it[0], r = it[1], dir = it[2];
            v[l] += (2*dir-1); v[l] = (v[l]+26)%26;
            if(r+1 < n) {v[r+1] -= (2*dir-1); v[r+1] = (v[r+1]+26)%26;}
        }
        s[0] = 'a' + (s[0] - 'a' + v[0])%26;
        for(int i = 1; i < n; i++) {
            s[i] = 'a' + (s[i-1] - 'a' + v[i])%26;
        }
        return s;
    }
};