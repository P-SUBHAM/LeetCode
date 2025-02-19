// Approach 1: brute
// Because each word len is <= 30 instead of iterating in wordlist and checkinf if its part of s.substr O(4000) inctead find substr of s O(30) and search in wordlist using set/unorderedset(~O(30*log4000/O(1)))
class Solution {
public:
    vector<string> dict;
    vector<string> ans;
    unordered_map<string,bool> memo;
    unordered_set<string> dicst;
    bool concatWord(string s, bool spl) {
        if(s.size()==0) return true;
        if(spl && memo.find(s)!=memo.end()) return memo[s];
        for(int i = 1; i <= s.size(); i++) {
            if(!spl && i==s.size()) continue;
            string word = s.substr(0,i);
            if(!spl && word == s) {
                continue;
            }
            int len = word.size();
            if(dicst.find(word)!=dicst.end()) {
                if(concatWord(s.substr(len,s.size()-len),true)) return memo[s] = true;
            }
        }
        if(spl) memo[s] = false;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        dict = words; ans.clear();
        for(auto word: words) dicst.insert(word);
        for(auto word: words) {
            if(concatWord(word,false)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};