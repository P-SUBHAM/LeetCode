class Solution {
public:
    vector<int> prefix_func(string needle) {
        int n = needle.size();
        vector<int> prefix(n);
        int j = 0;
        for(int i = 1; i < n; i++) {
            j = prefix[i-1];
            while(j > 0 && needle[i]!=needle[j]) {
                j = prefix[j-1];
            }
            if(needle[i] == needle[j]) {
                prefix[i] = j + 1;
            }
        }
        return prefix;
    }
    int strStr(string haystack, string needle) {
        vector<int> prefix = prefix_func(needle);
        for(auto it: prefix) cout<<it<<" "; cout<<endl;
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {// use while loop
            cout<<i<<j<<endl;
            if(haystack[i] == needle[j]) {
                j++;
            }
            else {
                bool con = false;
                while(j > 0 && haystack[i] != needle[j]) {
                    j = prefix[j-1]; con = true;
                }
                if(con) i--;
                cout<<j<<endl;
            }
            if(j == needle.size()) return i + 1 - needle.size();
        }
        return -1;
    }
};

// Approach 2: KMP 
// check the prefix logic of j = prefix[j-1]; // to not start from first but from last prefix matched
class Solution2 {
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

class Solution1 {
public:
    vector<int> lps(string str) {
        int n = str.size();
        vector <int> lpsv(n,0);
        int i(1), j(0);
        while(i < n) {
            if(str[i] == str[j]) {
                lpsv[i] = j + 1;
                i++;
                j++;
            }
            else {
                if(j != 0) {
                    j = lpsv[j-1];
                }
                else {
                    lpsv[i] = 0;
                    i++;
                }
            }
        }
        return lpsv;
    }
    
    int kmp(string s, string str) {
        vector<int> lpsv = lps(str);
        // for(auto it: lpsv) {
        //     cout<<it<<" ";
        // }
        int n = s.size();
        int i(0), j(0);
        while(i < n) {
            if(s[i] == str[j]) {
                i++;
                j++;
            }
            else {
                if(j != 0) {
                    j = lpsv[j-1];
                }
                else {
                    i++;
                }
            }
            if(j == str.size()) {
                return i - j;
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};