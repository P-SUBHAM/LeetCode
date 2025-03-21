class Solution {
public: // code here
    unordered_set<string> ans;
    void rec(string s, int size, map<char,int> &mp) {
        if(s.size()==size) {
            ans.insert(s); return;
        }
        map<char,int> tempmp = mp;
        for(auto it: tempmp) {
            char ch = it.first;
            if(--mp[ch] == 0) mp.erase(ch);
            rec(s+it.first,size,mp);
            mp[ch]++;
        }
    }
    int numTilePossibilities(string tiles) {
        map<char,int> mp;
        int n = tiles.size();
        for(auto ch: tiles) mp[ch]++;
        for(int i = 1; i <= n; i++) {
            rec("",i,mp);
        }
        return ans.size();
    }
};
// Approach 1: BruteForce as len <= 7
class Solution1 {
public:
    int cnt = 0;
    set<string> st;
    void f(string tiles, int tilelim, string s) {
        cnt++;
        if(s.size()==tilelim) {
            st.insert(s); return;
        }
        if(tiles.size()==0) {
            return;
        }
        for(int j = 0; j < tiles.size(); j++) {
            string newtiles = tiles.substr(0,(j-1)-0+1)+tiles.substr(j+1,tiles.size()-(j+1));
            f(newtiles,tilelim,s+tiles[j]);
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        for(int i = 1; i <= n; i++) {
            f(tiles,i,"");
        }
        // cout<<cnt<<endl;
        return st.size();
    }
};