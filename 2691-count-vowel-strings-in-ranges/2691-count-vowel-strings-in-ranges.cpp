class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        set<char> vowels = {'a','e','i','o','u'};
        vector <int> prefix(n+1,0), ans;
        for(int i = 1; i < n+1; i++) {
            prefix[i] = prefix[i-1] + (vowels.count(words[i - 1][0]) && vowels.count(words[i - 1].back()));
        }
        cout<<endl;
        for(auto p: prefix) cout<<" "<<p;
        for(auto q: queries) {
            int l = q[0], r = q[1];
            ans.push_back(prefix[r+1] - prefix[l]);
        }
        return ans;
    }
};