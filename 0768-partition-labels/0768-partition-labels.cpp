class Solution {
public:
    vector<int> func(string s, int i, unordered_map<char,int> &l) {
        if(i < 0) return {};
        int low = l[s[i]];
        for(int j = i; j > low; j--) {
            low = min(low,l[s[j]]);
        }
        int len = i - low + 1;
        vector<int> ans = func(s,low-1,l);
        ans.push_back(len);
        return ans;
    }
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> l, r;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(l.find(ch) == l.end()) {
                l[ch] = i;
            }
            r[ch] = i;
        }
        vector<int> ans;
        ans = func(s,n-1,l);
        return ans;
    }
};