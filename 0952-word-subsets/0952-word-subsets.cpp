// Approach 1: using character map
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size();
        map<char,int> subset;
        for(int i = 0; i < n2; i++) {
            map<char,int> currmp;
            for(int j = 0; j < words2[i].size(); j++) {
                char ch = words2[i][j];
                currmp[ch]++;
                subset[ch] = max(subset[ch],currmp[ch]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < words1.size(); i++) {
            map<char,int> currmp;
            for(int j = 0; j < words1[i].size(); j++) {
                char ch = words1[i][j];
                currmp[ch]++;
            }
            bool pos = true;
            for(auto it: subset) {
                if(currmp[it.first] < it.second) {
                    pos = false;
                    break;
                }
            }
            if(pos) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};