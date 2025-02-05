// Approach 1: BruteForce as len <= 7
class Solution {
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