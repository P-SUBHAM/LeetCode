class Solution {
public:
    int n;
    vector<vector<int>> pos;
    bool isSubseq(string &s, string &x, int i, int j) {
        if(j == x.size()) {
            return true;
        }
        if(i == n) {
            return false;
        }
        if(s[i] == x[j]) {
            return isSubseq(s,x,i+1,j+1);
        }
        int cno = x[j] - 'a';
        auto it = upper_bound(pos[cno].begin(),pos[cno].end(),i);
        int ind = it - pos[cno].begin();
        if(ind == pos[cno].size()) {
            return false;
        }
        return isSubseq(s,x,pos[cno][ind],j);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        n = s.size();
        pos.clear();
        pos.resize(26);
        for(int i = 0; i < n; i++) {
            pos[s[i]-'a'].push_back(i);
        }
        // printing next char's ocuurence index
        // for(int i = 0; i < 26; i++) {
        //     cout<<i<<": ";
        //     for(auto x: pos[i]) {
        //         cout<<x<<" ";
        //     }cout<<endl;
        // }
        for(auto x: words) {
            if(isSubseq(s,x,0,0)) {
                // cout<<x<<" ";
                ans++;
            }
        }
        return ans;
    }
};