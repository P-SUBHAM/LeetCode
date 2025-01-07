// Approach 1: brute, comparing each word with other
class Solution {
public:
bool comp(string s1, string s2) { // return if s1 in s2
    int n = s1.size();
    for(int i = 0; i <= s2.size()-n; i++) {
        if(s1 == s2.substr(i,n)) {
            return true;
        }
    }
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        sort(words.begin(),words.end(),[](string s1, string s2)->bool{return s1.size() > s2.size();});
        // for(auto it: words) cout<<it<<" "; cout<<endl;
        int n = words.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(comp(words[i],words[j])) { // i in j
                    ans.push_back(words[i]); break;
                } 
            }
        }
        return ans;
    }
};