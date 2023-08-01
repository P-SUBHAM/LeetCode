class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int i = 0;
        string ans = "";
        while(i < n1 && i < n2) {
            ans = ans + word1[i] + word2[i];
            i++;
        }
        while(i < n1) {
            ans = ans + word1[i];
            i++;
        }
        while(i < n2) {
            ans = ans + word2[i];
            i++;
        }
        return ans;
    }
};