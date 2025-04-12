class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++) s += string(1,'0'+i);
        while(--k && next_permutation(s.begin(),s.end()));
        return s;
    }
};