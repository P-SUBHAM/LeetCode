class Solution {
public:
    vector<string> ans;
    vector<string> dict;
    void wordBreakDP(string s, string comb) {
        if(s.size()==0) ans.push_back(comb.substr(1,comb.size()-1));
        for(auto word: dict) {
            int len = word.size();
            if(word == s.substr(0,len)) {
                wordBreakDP(s.substr(len,s.size()-len),comb+" "+word);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear(); dict = wordDict;
        wordBreakDP(s,"");
        return ans;
    }
};