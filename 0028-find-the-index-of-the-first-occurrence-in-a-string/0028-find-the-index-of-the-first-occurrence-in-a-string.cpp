// Approach 2: KMP 
// check the prefix logic of j = prefix[j-1]; // to not start from first but from last prefix matched
class Solution {
public:
    vector<int> prefixf(string s) {
        int n = s.size();
        vector<int> prefix(n,0);
        for(int i = 1; i < n; i++) {
            int j = prefix[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = prefix[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            prefix[i] = j;
        }
        return prefix;
    }
    int strStr(string haystack, string needle) {
        vector<int> prefix = prefixf(needle);
        int i = 0, j = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                if(j==0) {
                    i++;
                }
                else {
                    j = prefix[j-1];
                }
            }
            if(j == needle.size()) {
                return i - needle.size();
            }
        }
        return -1;
    }
};