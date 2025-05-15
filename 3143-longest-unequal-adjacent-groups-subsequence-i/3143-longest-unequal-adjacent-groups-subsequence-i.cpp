// Approach 1: greedy
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans = {words[0]};
        int lastBit = groups[0];
        for(int i = 1; i < n; i++) {
            if(groups[i] != lastBit) {
                ans.push_back(words[i]);
                lastBit = groups[i];
            }
        }
        return ans;
    }
};