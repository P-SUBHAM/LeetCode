// Approach 1: Brute
class Solution {
public:
    // checks if str1 is both prefix and suffix of str2
    bool isPrefixAndSuffix(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n1 > n2) {
            return false;
        }
        if(str1 == str2.substr(0,n1) && str1 == str2.substr(n2-n1,n1)) {
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isPrefixAndSuffix(words[i],words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};