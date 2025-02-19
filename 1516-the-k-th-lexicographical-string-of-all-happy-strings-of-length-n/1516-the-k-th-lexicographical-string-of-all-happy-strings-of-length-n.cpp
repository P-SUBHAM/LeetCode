// Approach 1: Brute
// Generate All Happy String of size n, sort and return kth lexicographic sequence
// HappyStr(n) = HappyStr(n-1) + "diff char than last char"
class Solution {
public:
    vector<string> HappyStr(int n) {
        if(n==1) return {"a","b","c"};
        vector<string> list;
        vector<string> basestr = HappyStr(n-1);
        for(auto str: basestr) {
            int len = str.size();
            char ch = str[len-1]; // last char : a b c
            char ch1 = 'a' + (ch-'a'+1)%3;
            char ch2 = 'a' + (ch-'a'+2)%3;
            list.push_back(str+ch1);
            list.push_back(str+ch2);
        }
        return list;
    }
    string getHappyString(int n, int k) {
        vector<string> ans = HappyStr(n);
        sort(ans.begin(),ans.end());
        // for(auto it: ans) cout<<it<<" "; cout<<endl; // All Happy strings of size n
        if(k > ans.size()) return "";
        return ans[k-1];
    }
};