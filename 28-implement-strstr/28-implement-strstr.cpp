class Solution {
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