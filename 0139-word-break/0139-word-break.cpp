// Approach 1: memoization DP
// if any word in dict matches prefix of s, then recursively check for latter part, use memoization
class Solution {
public:
    unordered_map<string,bool> memo;
    vector<string> dict;
    bool wordBreakDP(string s) {
        if(s.size()==0) return true;
        if(memo.find(s)!=memo.end()) return memo[s];
        for(auto word: dict) {
            if(s.substr(0,word.size())==word) {
                if(wordBreakDP(s.substr(word.size(),s.size()-word.size()))) {
                    return memo[s] = true;
                }
            }
        }
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        dict = wordDict;
        return wordBreakDP(s);
    }
};