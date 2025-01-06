// Approach 1 Char hashmap
// store p into hashmap, gen hashmap for s.substr and keep comparing
// Char hashmap O(1)
class Solution {
public:
    map<char,int> mapp, maps;
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), N = p.size();
        vector<int> ans;
        for(auto x: p) {mapp[x]++;} 
        for(int i = 0; i < N-1; i++) {maps[s[i]]++;}
        for(int j = N-1; j < n; j++) {
            maps[s[j]]++;
            if(maps == mapp) {ans.push_back(j - (N-1));}
            maps[s[j-(N-1)]]--;
            if (maps[s[j - (N - 1)]] == 0) {
                maps.erase(s[j - (N - 1)]);  // Erase the key if its count becomes 0
            }
        }
        return ans;
    }
};